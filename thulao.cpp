#include<bits/stdc++.h>
using namespace std;

#define task "rblock"
#define fi first
#define se second
#define fore(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define ford(i,a,b) for(ll i=(ll)(a);i>=(ll)(b);--i)

typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> pii;

const ll mxn=105;
ll n,m,w[mxn][mxn],trace[mxn],f[mxn];
vector<ll> a[mxn];

void dijkstra(ll s)
{
    fill(f+1,f+n+1,2e9);
    priority_queue<pii,vector<pii>,greater<pii>> q;
    f[s]=0;
    q.push({f[s],s});
    while(!q.empty())
    {
//        cout<<u<<' '<<len<<endl;
        ll u=q.top().se;
        ll len=q.top().fi;
//        cout<<u<<' '<<len<<endl;
        q.pop();
        if(f[u]<len) continue;
        for(ll v:a[u])
        {
            if(f[v]>f[u]+w[u][v])
            {
                f[v]=f[u]+w[u][v];
                trace[v]=u;
                q.push({f[v],v});
            }
        }
    }
//    cout<<f[n]<<endl;
}
void solve()
{
    cin>>n>>m;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=n;++j)
            if(i!=j) w[i][j]=2e9;
    for(ll i=1;i<=m;++i)
    {
        ll u,v,c;
        cin>>u>>v>>c;
        a[u].push_back(v);
        a[v].push_back(u);
        w[u][v]=min(w[u][v],c);
        w[v][u]=min(w[v][u],c);
    }

    dijkstra(1);
    ll cur=f[n];
    vector<ll> e;
    ll u=n;
    while(u!=0)
    {
        e.push_back(u);
        u=trace[u];
    }
//    cout<<cur<<endl;
    reverse(e.begin(),e.end());
    ll ans=0;
    for(ll i=1;i<e.size();++i)
    {
        ll u=e[i-1], v=e[i];
        ll tmp=w[u][v];
        w[u][v]=2*tmp;
        w[v][u]=2*tmp;
        dijkstra(1);
        ans=max(ans,f[n]-cur);
        w[u][v]=tmp;
        w[v][u]=tmp;
    }
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".in","r"))
    {
        freopen(task".in","r",stdin);
        freopen(task".out","w",stdout);
    }
    solve();
}


