#include<bits/stdc++.h>
using namespace std;
#define task "lnacs"
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

int n,m;
int a[1005],b[1005],dp[1005][1005];
void solve()
{
        cin>>n>>m;
        FOR(i,1,n) cin>>a[i];
        FOR(i,1,m) cin>>b[i];
        FOR(i,1,n)
        {
                FOR(j,1,m)
                {
                        if(a[i]==b[j])
                        {
                                if(i>1&&j>1) dp[i][j]=dp[i-2][j-2]+1;
                                else dp[i][j]=dp[i-1][j-1]+1;
                        }
                        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
        }
        cout<<dp[n][m];
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



