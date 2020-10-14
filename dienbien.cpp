#include<bits/stdc++.h>
using namespace std;
#define task "dienbien"
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

const int N=3e5+5;
int p[N],n,m,sol=0,w[N];
vector<int> a[N];

void dfs(int u, int pre)
{
    w[u]=p[u];
    for(int v:a[u])
    {
        if(v==pre) continue;
        dfs(v,u);
        w[u]+=w[v];
    }
    if(w[u]>=2&&p[u]) sol+=w[u],w[u]=1,--sol;
    else if(w[u]>=2&&!p[u]) ++sol,w[u]=0;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        a[i].clear();
        p[i]=0;
    }
    if(n==-1) exit(0);
    for(int i=1;i<=m;++i)
    {
        int x;
        cin>>x;
        p[x]=1;
    }
    int ok=1;
    sol=0;
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
        if(p[u]&&p[v]) ok=0;
    }
    if(!ok)
    {
        cout<<-1<<'\n';
        return;
    }
    dfs(1,1);
    cout<<sol<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t;
    cin>>t;
    while(1) solve();
}





