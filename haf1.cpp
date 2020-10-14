#include<bits/stdc++.h>
using namespace std;
#define task "haf1"
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

int n,m,a[1005][1005],dp[1005][1005];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j) cin>>a[i][j];
    for(int i=1;i<=n;++i) dp[1][i]=a[1][i];

    for(int i=2;i<=m;++i)
    {
        for(int j=1;j<=n;++j) dp[i][j]=dp[i-1][j]+a[i][j];
        for(int j=2;j<=n;++j) dp[i][j]=min(dp[i][j],dp[i][j-1]+a[i][j]);
        for(int j=n-1;j>=1;--j) dp[i][j]=min(dp[i][j+1]+a[i][j],dp[i][j]);
    }
    int ans=2e9;
    for(int i=1;i<=n;++i) ans=min(ans,dp[m][i]);
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





