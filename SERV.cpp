#include<bits/stdc++.h>
using namespace std;
#define task "serv"
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

int n,m,a[205][205],ord[1005];
ll dp[1005][205][205];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j) cin>>a[i][j];
    for(int i=1;i<=m;++i) cin>>ord[i];
    for(int k=0;k<=m;++k)
    for(int i=0;i<=n;++i)
    for(int j=0;j<=n;++j) dp[k][i][j]=1e14;
    ord[0]=3;
    dp[0][1][2]=0;
    for(int k=0;k<m;++k)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(i==j||j==ord[k]||ord[k]==i) continue;
                if(dp[k][i][j]>=1e14) continue;

                dp[k+1][i][ord[k]]=min(dp[k+1][i][ord[k]],dp[k][i][j]+a[j][ord[k+1]]);
                dp[k+1][j][ord[k]]=min(dp[k+1][j][ord[k]],dp[k][i][j]+a[i][ord[k+1]]);
                dp[k+1][i][j]=min(dp[k+1][i][j],dp[k][i][j]+a[ord[k]][ord[k+1]]);
            }
        }
    }
    ll ans=1e14;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
    if(i!=j&&j!=ord[m]&&ord[m]!=i) ans=min(ans,dp[m][i][j]);
    cout<<ans;
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





