#include<bits/stdc++.h>
using namespace std;
#define task "disney1"
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

int n,a[205][205],dp[205][205];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j) cin>>a[i][j];

    for(int i=0;i<=n;++i)
    for(int j=0;j<=n;++j) dp[i][j]=1e9;
    dp[1][1]=0;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=i;++j)
    {
        if(dp[i][j]>=1e9) continue;
        dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a[i][i+1]);
        dp[i][i+1]=min(dp[i][i+1],dp[i][j]+a[j][i+1]);
        dp[j][i+1]=dp[i+1][j];
        dp[i+1][i]=dp[i][i+1];
        if(j==i-1)
        {
            dp[i][j+1]=min(dp[i][j+1],dp[i][j]+a[j][j+1]);
            dp[j+1][i]=dp[i][j+1];
        }
    }
//    cout<<dp[4][4]<<endl;
    int ans=1e9;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
    if(i==n||j==n)
    {
        int tmp=dp[i][j];
        tmp+=a[i][1]+a[j][1];
        ans=min(ans,tmp);
    }
//    cout<<dp[1][3]<<endl;
    cout<<ans<<endl;
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





