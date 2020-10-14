#include<bits/stdc++.h>
using namespace std;
#define task "stnode"
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
const int N=1e4+5;

int n,m,s,t,cha[N],vis[N],pos[N],mx;
vector<int> adj[N];

void dfs(int u)
{
    vis[u]=1;
    for(int v:adj[u])
    {
        if(!vis[v])
        {
            cha[v]=u;
            dfs(v);
        }
    }
}
void rundfs(int u)
{
    vis[u]=1;
    for(int v:adj[u])
    {
        mx=max(mx,pos[v]);
        if(pos[v]||vis[v]) continue;
        rundfs(v);
    }
}
void biot()
{
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
    }
    dfs(s);
    vector<int> path;
    int tam=t;
    while(cha[tam]!=0)
    {
        path.pb(tam);
        tam=cha[tam];
    }
    path.pb(s);
    reverse(ALL(path));
    for(int i=0;i<zs(path);++i) pos[path[i]]=i+1;
    int ans=0;
    for(int i=1;i<=n;++i) vis[i]=0;
    for(int i:path)
    {
        if(pos[i]>=mx) ++ans;
        rundfs(i);
    }
    ans-=2;
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








