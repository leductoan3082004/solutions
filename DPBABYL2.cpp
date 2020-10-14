#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "DPBABYL2"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<ll,ll> pii;

struct three
{
    ll x,y,z;
};
const ll mxn=3*16006;
ll n,st[4*mxn];
vector<ll> s;
vector<three> a;

void update(ll i, ll l, ll r, ll p, ll val)
{
    if(p>r||p<l) return;
    if(l==r) {
        st[i]=max(st[i],val);
        return;
    }
    ll mid=(l+r)>>1;
    update(i<<1,l,mid,p,val);
    update(i<<1|1,mid+1,r,p,val);
    st[i]=max(st[i<<1],st[i<<1|1]);
}
ll get(ll i, ll l, ll r, ll u, ll v)
{
    if(u>r||v<l) return 0;
    if(u<=l&&r<=v) return st[i];
    ll mid=(l+r)>>1;
    return max(get(i<<1,l,mid,u,v),get(i<<1|1,mid+1,r,u,v));
}
bool cmp(three a, three b)
{
    if(a.x!=b.x) return a.x>b.x;
    return a.y<b.y;
}
void solve()
{
    cin>>n;
    if(n==0) exit(0);
    a.clear();
    s.clear();
    for(ll i=1;i<=4*3*n;++i) st[i]=0;
    for(ll i=1;i<=n;++i) {
        vector<ll> tmp(3);
        cin>>tmp[0]>>tmp[1]>>tmp[2];
        do {
            a.push_back({tmp[0],tmp[1],tmp[2]});
        }
        while(next_permutation(tmp.begin(),tmp.end()));
        s.push_back(tmp[0]);
        s.push_back(tmp[1]);
        s.push_back(tmp[2]);
    }
    s.push_back(-1);
    sort(a.begin(),a.end(),cmp);
    sort(s.begin(),s.end());
    s.resize(unique(s.begin(),s.end())-s.begin());

    n*=3;
    ll ans=0;
    for(ll i=0;i<a.size();++i) {
        ll k=lower_bound(s.begin(),s.end(),a[i].y)-s.begin();
        ll mx=get(1,1,n+5,k+1,n+5)+a[i].z;
        ans=max(ans,mx);
        update(1,1,n+5,k,mx);
    }
    cout<<ans<<'\n';
}
int main()
{
    TL
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    while(1) solve();
}
/// JUST KEEP TRAINING





