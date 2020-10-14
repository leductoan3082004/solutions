#include<bits/stdc++.h>
using namespace std;
#define task "LQDGONME"
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

int n,m,a[15][1005],pos[15][1005],dp[1005];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    for(int j=1;j<=n;++j)
    {
        cin>>a[i][j];
        pos[i][a[i][j]]=j;
    }
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        dp[i]=1;
        for(int j=1;j<i;++j)
        {
            int ok=1;
            for(int k=1;k<=m;++k) ok&=pos[k][a[1][i]]>pos[k][a[1][j]];
            if(ok) dp[i]=max(dp[i],dp[j]+1);
        }
        ans=max(ans,dp[i]);
    }
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





