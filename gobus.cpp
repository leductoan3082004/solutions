#include<bits/stdc++.h>

using namespace std;

#define task "GOBUS"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define zs(v) ((ll)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(),(v).end()

#define FOR(i,a,b) for(ll i=(a);i<=(b);++i)
#define ROF(i,b,a) for(ll i=(b);i>=(a);--i)
#define REP(i,a,b) for(ll i=(a);i<(b);++i)

typedef long double ld;
typedef long long ll;
typedef pair<ll,ll> pii;

const ll dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const ll dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1000000007; /// 998244353
const ll base=311;
template <typename T>
inline void read(T& x)
{
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' | c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}


const ll N=1e5+5;
vector<ll> s;
pii a[N];
ll st[8*N];
ll n,m;

void add(ll &a, ll b)
{
    a=(a+b)%mod;
}
void upd(ll i, ll l, ll r, ll p, ll val)
{
    if(l==r)
    {
        st[i]=(st[i]+val)%mod;
        return;
    }
    ll mid=(l+r)>>1;
    if(p<=mid) upd(i<<1,l,mid,p,val);
    else upd(i<<1|1,mid+1,r,p,val);
    st[i]=(st[i<<1]+st[i<<1|1])%mod;
}
ll get(ll i, ll l, ll r, ll u, ll v)
{
    if(u>r||v<l) return 0;
    if(u<=l&&r<=v) return st[i];
    ll mid=(l+r)>>1;
    return (get(i<<1,l,mid,u,v)+get(i<<1|1,mid+1,r,u,v))%mod;
}
bool cmp(pii a, pii b)
{
    return a.se<b.se;
}
void biot()
{
    read(m); read(n);
    for(ll i=1;i<=n;++i)
    {
        read(a[i].fi); read(a[i].se);
        s.pb(a[i].fi);
        s.pb(a[i].se);
    }
    s.pb(n);
    s.pb(0);
    s.pb(-1);

    sort(ALL(s));
    s.resize(unique(ALL(s))-s.begin());

    upd(1,1,zs(s),1,1);

    sort(a+1,a+n+1,cmp);

//    for(ll i=1;i<=n;++i) cout<<a[i].fi<<' '<<a[i].se<<'\n';

    for(ll i=1;i<=n;++i)
    {
        ll l=lb(ALL(s),a[i].fi)-s.begin();
        ll r=lb(ALL(s),a[i].se)-s.begin();
        ll val=get(1,1,zs(s),l,r-1);
        upd(1,1,zs(s),r,val);
    }
    ll id=lb(ALL(s),m)-s.begin();
    cout<<get(1,1,zs(s),id,id);
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
