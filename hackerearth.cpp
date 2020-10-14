#include<bits/stdc++.h>
using namespace std;
#define task "hackerearth"
#define BIT(x, i) (((x) >> (i)) & 1)
#define lb lower_bound
#define ub upper_bound
#define lla(v) (v).begin(),(v).end()
#define zs(v) (v).size()
#define fi first
#define se second
#define pb push_back
#define ar array
typedef long double ld;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll mod=1000000007; /// 998244353
const ll base=311;
const ll N=1e5+5;

pii st[2][4*N];
ll n,a[N];

pii mer(pii a, pii b)
{
    pii ans;
    if(a.fi==b.fi) ans={a.fi,(a.se+b.se)%mod};
    else ans=max(a,b);
    return ans;
}
void upd(ll id, ll i, ll l, ll r,ll pos, pii p)
{
    if(l==r)
    {
        st[id][i]=mer(st[id][i],p);
        return;
    }
    ll mid=(l+r)>>1;
    if(pos<=mid) upd(id,i<<1,l,mid,pos,p);
    else upd(id,i<<1|1,mid+1,r,pos,p);
    st[id][i]=mer(st[id][i<<1],st[id][i<<1|1]);
}
pii get(ll id, ll i, ll l, ll r, ll u, ll v)
{
    if(u>r||v<l) return {0,0};
    if(u<=l&&r<=v) return st[id][i];
    ll mid=(l+r)>>1;
    return mer(get(id,i<<1,l,mid,u,v),get(id,i<<1|1,mid+1,r,u,v));
}
void solved()
{
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i];
    for(ll i=1;i<=n;++i)
    {
        if(a[i]>0)
        {
            pii tam=get(0,1,1,N,1,a[i]-1);
            if(tam.fi==0) tam.se=1;
            tam.fi++;
            upd(1,1,1,N,a[i],{tam.fi,tam.se});
        }
        else
        {
            pii tam=get(1,1,1,N,1,-a[i]-1);
            if(tam.fi==0) tam.se=1;
            tam.fi++;
            upd(0,1,1,N,-a[i],{tam.fi,tam.se});
        }
    }
    ll sol=0,ans=0;
    if(st[0][1].fi==st[1][1].fi) sol=st[0][1].fi, ans=(st[0][1].se+st[1][1].se)%mod;
    else if(st[0][1]>st[1][1]) sol=st[0][1].fi, ans=st[0][1].se;
    else sol=st[1][1].fi, ans=st[1][1].se;
    cout<<sol<<' '<<ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    solved();
}
