#include<bits/stdc++.h>
using namespace std;
#define task "mtree"
#define FOR(i,a,b) for(ll i=(a),_b=(b);i<=_b;++i)
#define FORD(i,b,a) for(ll i=(b),_a=(a);i>=_a;--i)
#define lb lower_bound
#define ub upper_bound
#define ALL(v) (v).begin(),(v).end()
#define zs(v) ll((v).size())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long double ld;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll mod=1000000007; /// 998244353
const ll base=311;
const ll N=1e5+5;

vector<pii>dsk[N];
ll n;
ll ans=0,dp[N];

void dfs(ll u, ll pre)
{
    dp[u]=1;
    for(int i=0;i<zs(dsk[u]);++i)
    {
        int v=dsk[u][i].fi, w=dsk[u][i].se;
        if(v==pre) continue;
        dfs(v,u);
        dp[u]=(dp[u]+dp[v]*w%mod)%mod;
    }
    for(int i=0;i<zs(dsk[u]);++i)
    {
        int v=dsk[u][i].fi,w=dsk[u][i].se;
        if(v==pre) continue;
        ll tam=dp[v]*w%mod;
        tam=tam*(dp[u]-tam+1+mod*mod)%mod;
        ans=(ans+tam)%mod;
    }
}
void biot()
{
    cin>>n;
    for(ll i=1;i<n;++i)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        dsk[u].pb(mp(v,w));
        dsk[v].pb(mp(u,w));
    }
    dfs(1,1);
    if(ans&1) cout<<(ans+mod)/2;
    else cout<<ans/2;
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








