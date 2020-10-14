#include<bits/stdc++.h>
using namespace std;
#define task "nsrail"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define mp make_pair
#define ALL(v) (v).begin(), (v).end()
#define __builtin_popcount __builtin_popcountll
#define rep(i,a,b) for (int i = (a), _b = (b); i <= _b; ++i)
#define repd(i,b,a) for (int i = (b), _a = (a); i >= _a; --i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const int N=505;
int n,k,a[N][N];
ll dp[N][N],f[N][N];
ll get(int u, int v, int x, int y)
{
    return f[x][y]-f[u-1][y]-f[x][v-1]+f[u-1][v-1];
}
ll cost(int l, int r)
{
    return get(l,r+1,r,n);
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j) cin>>a[i][j];

    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j) if(i<=j) a[i][j]+=a[j][i];
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j) f[i][j]=a[i][j]+f[i-1][j]+f[i][j-1]-f[i-1][j-1];

    for(int i=0;i<=n;++i)
    for(int j=0;j<=k;++j) dp[i][j]=-1e15;
    dp[0][0]=0;
    for(int i=1;i<=n-1;++i)
    {
        for(int c=0;c<=k;++c)
        {
            for(int j=0;j<i;++j)
            {
                dp[i][c]=max(dp[i][c],dp[j][c]);
                if(c) dp[i][c]=max(dp[i][c],dp[j][c-1]+cost(j+1,i));
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=n-1;++i)
    for(int j=0;j<=k;++j) ans=max(ans,dp[i][j]);
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


