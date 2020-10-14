#include<bits/stdc++.h>

using namespace std;

#define task "demso"
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> ii;

ll a,b;
int d,k;
ll dp[20][20][20][2];

ll cal(ll val)
{
        vector<int> digit;
        while(val>0) {
                digit.push_back(val%10);
                val/=10;
        }
        int n=digit.size();
        /// dp[i][digit][k][1/0]
        digit.push_back(0);
        reverse(digit.begin(),digit.end());
        for(int i=0;i<=n;++i)
                for(int j=0;j<=9;++j)
                        for(int c=0;c<=k;++c)
                                dp[i][j][c][0]=dp[i][j][c][1]=0;

        for(int i=0;i<=9;++i)
                if(i>digit[n]) dp[n][i][0][1]=1;
                else dp[n][i][0][0]=1;

        for(int i=n-1;i>=0;--i) {
                for(int j1=0;j1<=9;++j1) {
                        for(int j2=0;j2<=9;++j2) {
                                for(int c=0;c<=k;++c) {
                                        if(abs(j1-j2)>d) {
                                                if(j1>digit[i]) {
                                                        dp[i][j1][c][1]+=dp[i+1][j2][c][1]+dp[i+1][j2][c][0];
                                                }
                                                else if(j1<digit[i]) {
                                                        dp[i][j1][c][0]+=dp[i+1][j2][c][1]+dp[i+1][j2][c][0];
                                                }
                                                else if(j1==digit[i]) {
                                                        dp[i][j1][c][0]+=dp[i+1][j2][c][0];
                                                        dp[i][j1][c][1]+=dp[i+1][j2][c][1];
                                                }
                                        }
                                        else {
                                                if(j1>digit[i]) {
                                                        dp[i][j1][c+1][1]+=dp[i+1][j2][c][1]+dp[i+1][j2][c][0];
                                                }
                                                else if(j1<digit[i]) {
                                                        dp[i][j1][c+1][0]+=dp[i+1][j2][c][0]+dp[i+1][j2][c][1];
                                                }
                                                else if(j1==digit[i]) {
                                                            dp[i][j1][c+1][0]+=dp[i+1][j2][c][0];
                                                            dp[i][j1][c+1][1]+=dp[i+1][j2][c][1];
                                                }
                                        }
                                }
                        }
                }
        }
        ll ans=0;

        for(int i=1;i<=n;++i) {
                for(int j=1;j<=9;++j) {
                        for(int c=0;c<=k;++c) {
                                if(i==1) ans+=dp[i][j][c][0];
                                else ans+=dp[i][j][c][1]+dp[i][j][c][0];
                        }
                }
        }
        return ans;
}
void solve()
{
    cin>>a>>b>>d>>k;
    cout<<cal(b)-cal(a-1);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ifstream cin("demso.inp");
    ofstream cout("demso.out");
    solve();
}





