#include<bits/stdc++.h>
using namespace std;
#define task "robotdhmt"
#define fi first
#define se second
#define fore_(i,a,b) for(ll i=(ll)(a);i<(ll)(b);++i)
#define fore(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define ford(i,a,b) for(ll i=(ll)(a);i>=(ll)(b);--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> pii;

const ll mxn=5005;
ll n,m,k;
ll dx[]={-1,0,1,1,1,0,-1,-1};
ll dy[]={-1,-1,-1,0,1,1,1,0};
vector<vector<ll>> a,f[7];
vector<pii> p;

struct three
{
    ll x,y;
    ll len;
};
struct cmp
{
    bool operator()(const three &a, const three &b)
    {
        return a.len>b.len;
    }
};
void dijkstra(ll t, ll x, ll y)
{
    f[t][x][y]=0;
    priority_queue<three,vector<three>,cmp> q;
    q.push({x,y,0});
    while(!q.empty())
    {
        x=q.top().x;
        y=q.top().y;
        ll len=q.top().len;
//        cout<<x<<' '<<y<<endl;
        q.pop();
        if(f[t][x][y]<len) continue;
        fore(i,0,7)
        {
            ll u=dx[i]+x;
            ll v=dy[i]+y;
            if(!(u>=1&&u<=n&&v>=1&&v<=m)) continue;
            ll w=max(f[t][x][y]+1,a[u][v]);
            if(f[t][u][v]>w)
            {
                f[t][u][v]=w;
                q.push({u,v,w});
            }
        }
    }
}
void solve()
{
    cin>>n>>m>>k;
    a=vector<vector<ll>> (n+5,vector<ll>(m+5));

    fore(i,0,k)
        f[i]=vector<vector<ll>> (n+5,vector<ll>(m+5,1e15));

    fore(i,1,n)
        fore(j,1,m)
        {
            cin>>a[i][j];
            if(a[i][j]==-1) p.push_back({i,j});
        }
//    dijkstra(0,1,1);
    fore(i,0,(int)p.size()-1)
    {
        dijkstra(i,p[i].fi,p[i].se);
    }
    ll ans=1e15;
    fore(i,1,n)
        fore(j,1,m)
        {
            ll tmp=-1;
            fore(t,0,k-1)
                tmp=max(tmp,f[t][i][j]);
            ans=min(ans,tmp);
        }
    if(ans==1e15) cout<<-1;
    else
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


