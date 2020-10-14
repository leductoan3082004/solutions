#include<bits/stdc++.h>
using namespace std;
#define task "scollect"
#define lwb lower_bound
#define upb upper_bound
#define ar array
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

int n,m;
string a[200];
int dp[200][200][500];
void solve()
{
    cin>>m>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        a[i]=' '+a[i];
    }
    for(int i=0;i<=n;++i)
    for(int j=0;j<=n;++j)
    for(int k=0;k<=m+n;++k) dp[i][j][k]=-1e9;
    dp[1][1][0]=(a[1][1]=='*');
    for(int k=1;k<=m+n-2;++k)
    {
        for(int i1=1;i1<=n;++i1)
        {
            for(int i2=1;i2<=n;++i2)
            {
                int j1=k-i1+2,j2=k-i2+2;
                int w=0;
                if(i1>=1&&i1<=n&&i2>=1&&i2<=n&&j1>=1&&j1<=m&&j2>=1&&j2<=m) {}
                else continue;
//                if(i1==2&&i2==2) cout<<j1<<' '<<j2<<endl;
//                if(i1==1&&i2==1) cout<<j1<<' '<<j2<<endl;
                if(a[i1][j1]=='#'||a[i2][j2]=='#') continue;
                if(a[i1][j1]=='*') ++w;
                if(i1==i2&&j1==j2) {}
                else w+=(a[i2][j2]=='*');
                dp[i1][i2][k]=max(dp[i1][i2][k],dp[i1-1][i2-1][k-1]+w);
//                if(i1==2&&i2==2&&k==1) cout<<i1<<' '<<i2<<' '<<dp[i1][i2][k]<<endl;
                dp[i1][i2][k]=max(dp[i1][i2][k],dp[i1-1][i2][k-1]+w);
                dp[i1][i2][k]=max(dp[i1][i2][k],dp[i1][i2-1][k-1]+w);
                dp[i1][i2][k]=max(dp[i1][i2][k],dp[i1][i2][k-1]+w);
            }
        }
    }
//    cout<<dp[2][2][1]<<endl;
    cout<<max(0,dp[n][n][n+m-2])<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    solve();
}





