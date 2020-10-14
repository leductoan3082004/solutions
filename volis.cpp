#include<bits/stdc++.h>
using namespace std;
#define task "volis"
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

int n,d,a[1005],dp[1005];

void solve()
{
    cin>>n>>d;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) dp[i]=2e9+9;
    dp[0]=-1e9;
    for(int i=1;i<=n;++i)
    {
        for(int j=i;j>=1;--j)
        {
            if(a[i]+d<dp[j-1]) continue;
            /// a[i]+d>=dp[j-1] && dp[j-1]>=a[i]-d
            /// a[i]+d>=dp[j-1] && dp[j-1]<=a[i]-d
            ///if(a[i]-d<=dp[j-1]) dp[j]=min(dp[j],dp[j-1]);
            dp[j]=min(dp[j],max(dp[j-1],a[i]-d));
        }
    }
    int ans;
    for(int i=n;i>=1;--i) if(dp[i]!=2e9+9) {ans=i; break;}
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





