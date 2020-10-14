#include<bits/stdc++.h>
using namespace std;
#define task "hackerrank"
#define lb lower_bound
#define ub upper_bound
#define ALL(v) (v).begin(),(v).end()
#define zs(v) (int)(v).size()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define cntbit __builtin_popcountll
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1000000007; /// 998244353
const int base=311;
const int N=1e5+5;

int n,m,root,color[N];
vector<int> adj[N];
set<int> s[N];

void dfs(int u, int pre)
{
    s[u].insert(color[u]);
    for(int v:adj[u])
    {
        if(v==pre) continue;
        dfs(v,u);
        if(zs(s[u])<zs(s[v])) swap(s[u],s[v]);
        s[u].insert(s[v].begin(),s[v].end());
    }
}
void biot()
{
    cin>>n>>m>>root;
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=1;i<=n;++i) cin>>color[i];
    dfs(root,root);
    while(m--)
    {
        int u; cin>>u;
        cout<<zs(s[u])<<'\n';
    }
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











