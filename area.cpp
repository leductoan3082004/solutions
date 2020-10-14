#include<bits/stdc++.h>
using namespace std;
#define task "area"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define pf pop_front
#define mp make_pair
#define zs(v) ((ll)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(),(v).end()

#define FOR(i,a,b) for(ll i=(a);i<=(b);++i)
#define FORD(i,b,a) for(ll i=(b);i>=(a);--i)
#define REP(i,a,b) for(ll i=(a);i<(b);++i)

typedef long double ld;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const ll dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1000000007; /// 998244353
const ll base=311;
const ll N=1e5+5;

struct three
{
    ll x,ys,yt,t;
};
vector<three> q;
ll ans=0;
ll n;
pii st[4*50000];

bool cmp(three a, three b)
{
    if(a.x!=b.x) return a.x<b.x;
    else return a.t>b.t;
}
void upd(ll u, ll v, ll val, ll i=1, ll l=0, ll r=30000)
{
    if(u>r||v<l) return;
    if(u<=l&&r<=v)
    {
        st[i].se+=val;
        if(st[i].se) st[i].fi=(r-l+1);
        else st[i].fi=st[i<<1].fi+st[i<<1|1].fi;
        return;
    }
    ll mid=(l+r)>>1;
    upd(u,v,val,i<<1,l,mid);
    upd(u,v,val,i<<1|1,mid+1,r);
    if(!st[i].se) st[i].fi=st[i<<1].fi+st[i<<1|1].fi;
}
void biot()
{
    cin >> n;
    for(ll i=1;i<=n;++i)
    {
        ll x,y,u,v; cin>>x>>y>>u>>v;
        ++y;
        q.pb({x,y,v,1});
        q.pb({u,y,v,-1});
    }
    sort(ALL(q),cmp);
    for(ll i=0;i<zs(q);++i)
    {
        if(i) ans+=(q[i].x-q[i-1].x)*st[1].fi;
        //cout<<q[i].ys<<' '<<q[i].yt<<'\n';
        upd(q[i].ys, q[i].yt, q[i].t);
    }
    cout << ans;
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
    return 0;
}
