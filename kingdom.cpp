#include<bits/stdc++.h>
using namespace std;
#define task "kingdom"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define mp make_pair
#define ALL(v) (v).begin(), (v).end()
#define dembit __builtin_popcountll
#define rep(i,a,b) for (ll i = (a), _b = (b); i <= _b; ++i)
#define repd(i,b,a) for (ll i = (b), _a = (a); i >= _a; --i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> ii;

template <typename T>
inline void read(T& x)
{
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' | c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}
int n,m,c[105],w[105],dp[2][105][2005];
vector<int>a[105];

void dfs(int u, int pre)
{
    dp[0][u][w[u]]=c[u];
    for(int i=0;i<a[u].size();++i)
    {
        int v=a[u][i];
        if(v==pre) continue;
        dfs(v,u);
        for(int j=0;j<=m;++j)
        {
            dp[1][u][j]=dp[0][u][j];
            for(int j1=0;j1<=j-w[u];++j1)
            {
                if(dp[0][v][j1]<0) continue;
                dp[1][u][j]=max(dp[1][u][j],dp[0][u][j-j1]+dp[0][v][j1]);
            }
        }
        for(int j=0;j<=m;++j) dp[0][u][j]=dp[1][u][j], dp[1][u][j]=0;
    }
}

void solve()
{
    read(n); read(m);
    for(int i=2;i<=n;++i) read(c[i]);
    for(int i=2;i<=n;++i) read(w[i]);
    for(int i=1;i<n;++i)
    {
        int u,v;
        read(u); read(v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=1;i<=n;++i)
    for(int j=0;j<=m;++j) dp[0][i][j]=dp[1][i][j]=-1e9;
    dfs(1,1);
    int ans=0;
//    cout<<dp[0][5][2]<<endl;
    for(int i=0;i<=m;++i) ans=max(ans,dp[0][1][i]);
    write(ans);
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






