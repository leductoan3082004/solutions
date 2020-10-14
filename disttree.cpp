#include<bits/stdc++.h>

using namespace std;

#define task "disttree"
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> ii;

const int mod=998244353;
const int mxn=50005;

int n,k,f[mxn][505];
vector<int> a[mxn];
ll ans=0;
void dfs(int u, int pre)
{
    f[u][0]=1;
    for(int v:a[u])
    {
        if(v==pre) continue;
        dfs(v,u);
        for(int i=0;i<k;++i) ans+=f[u][i]*f[v][k-i-1];
        for(int i=0;i<k;++i) f[u][i+1]+=f[v][i];
    }
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(1,1);
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






