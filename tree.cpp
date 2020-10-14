#include<bits/stdc++.h>
using namespace std;
#define task "tree"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define mp make_pair
#define rep(i,a,b) for (ll i = (a), _b = (b); i <= _b; ++i)
#define repd(i,b,a) for (ll i = (b), _a = (a); i >= _a; --i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;


int n,p[5005],dp[5005][5005],w[5005];
vector<int> a[5005];

void dfs1(int u, int pre)
{
    if(a[u].size()==1&&u!=1) w[u]=1;
    for(int v:a[u])
    {
        if(v==pre) continue;
        dfs1(v,u);
        w[u]+=w[v];
    }
}
void dfs(int u, int pre)
{
    int cnt=0;
    for(int v:a[u])
    {
        if(v==pre) continue;
        dfs(v,u);
        ++cnt;
    }
    if(cnt==0)
    {
        dp[u][0]=min(dp[u][0],p[u]);
        dp[u][1]=min(dp[u][1],abs(p[u]-1));
    }
    if(cnt==1)
    {
        int v=0;
        for(int j:a[u])
        if(j!=pre) {v=j; break;}
        for(int j=0;j<=w[u];++j)
            if(dp[v][j]!=1e9)
                dp[u][j]=min(dp[u][j],dp[v][j]+abs(p[u]-j));
    }
    if(cnt==2)
    {
        int v1=-1, v2=-1;
        for(int v:a[u])
        {
            if(v==pre) continue;
            if(v1==-1) v1=v;
            else v2=v;
        }
//        if(u==1) cout<<v1<<' '<<v2<<endl;
        for(int j1=0;j1<=w[v1];++j1)
        {
            for(int j2=0;j2<=w[v2];++j2)
            {
                if(dp[v1][j1]==1e9||dp[v2][j2]==1e9) continue;
                dp[u][j1+j2]=min(dp[u][j1+j2],dp[v1][j1]+dp[v2][j2]+abs(p[u]-j1-j2));
            }
        }
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>p[i];
    if(n==1)
    {
        cout<<min(abs(1-p[1]),p[1]);
        return;
    }
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    rep(i,1,n) rep(j,0,5000) dp[i][j]=1e9;
    dfs1(1,1);
    dfs(1,1);
    int ans=1e9;
    for(int i=0;i<=w[1];++i) ans=min(ans,dp[1][i]);
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






