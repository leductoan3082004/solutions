#include<bits/stdc++.h>
using namespace std;
#define task "upgranet"
#define lb lower_bound
#define ub upper_bound
#define ALL(v) (v).begin(),(v).end()
#define zs(v) int((v).size())
#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,b,a) for(int i=(b),_a=(a);i>=_a;--i)
#define FOR_(i,a,b) for(int i=(a),_b=(b);i<_b;++i)

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1000000007; /// 998244353
const int base=311;
const int N=1e5+5;

struct trip
{
    int u,v,w;
};
vector<trip> e,remain;
int cha[N],n,m,h[N];
vector<pii> adj[N];
pii anc[N][30];

bool comp(trip a, trip b)
{
    return a.w>b.w;
}
int root(int u)
{
    if(cha[u]<0) return u;
    else return cha[u]=root(cha[u]);
}
void dsu(int u, int v)
{
    u=root(u), v=root(v);
    if(u==v) return;
    if(cha[u]>cha[v]) swap(u,v);
    cha[u]+=cha[v];
    cha[v]=u;
}
void dfs(int u, int pre)
{
    for(int i=0;i<zs(adj[u]);++i)
    {
        int v=adj[u][i].fi, w=adj[u][i].se;
        if(v==pre) continue;
        h[v]=h[u]+1;
        anc[v][0].fi=u;
        anc[v][0].se=w;
        dfs(v,u);
    }
}
void setupLCA()
{
    for(int i=1;i<=n;++i)
        for(int j=0;j<=log2(n);++j)
            anc[i][j].se=1e9;
    dfs(1,1);
    for(int j=1;j<=log2(n);++j)
    {
        for(int i=1;i<=n;++i)
        {
            anc[i][j].fi=anc[anc[i][j-1].fi][j-1].fi;
            anc[i][j].se=min(anc[i][j-1].se,anc[anc[i][j-1].fi][j-1].se);
        }
    }
}
int LCA(int u, int v)
{
    if(h[u]<h[v]) swap(u,v);
    int k=log2(h[u]);
    int mx=2e9;
//    cout<<k<<endl;
//    cout<<anc[6][0].se<<endl;
    for(int i=k;i>=0;--i)
    {
        if(h[u]-(1<<i)>=h[v])
        {
            mx=min(mx,anc[u][i].se);
            u=anc[u][i].fi;
        }
    }
//    cout<<anc[6][1].fi<<endl;
    if(u==v) return mx;
    for(int i=k;i>=0;--i)
    {
        if(anc[u][i].fi&&anc[u][i].fi!=anc[v][i].fi)
        {
            mx=min({mx,anc[u][i].se,anc[v][i].se});
            u=anc[u][i].fi;
            v=anc[v][i].fi;
        }
    }
    return min({mx,anc[u][0].se,anc[v][0].se});
}
void biot()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int u,v,c;
        cin>>u>>v>>c;
        e.pb({u,v,c});
    }
    sort(ALL(e),comp);
    fill(cha+1,cha+n+1,-1);
    for(trip i:e)
    {
        if(root(i.u)==root(i.v))
        {
            remain.pb(i);
            continue;
        }
        dsu(i.u,i.v);
        adj[i.u].pb(mp(i.v,i.w));
        adj[i.v].pb(mp(i.u,i.w));
    }
    setupLCA();
//    cout<<LCA(4,5)<<endl;
    ll ans=0;
    for(trip i:remain)
    {
        int u=i.u, v=i.v, w=i.w;
        int mx=LCA(u,v);
//        cout<<u<<" "<<v<<" "<<w<<" "<<mx<<endl;
        ans+=max(0,mx-w);
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
    biot();
}








