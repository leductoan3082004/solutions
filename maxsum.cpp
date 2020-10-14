#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "maxsum"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<ll,ll> pii;

const ll mxn=1e5+5;
const ll oo=1e14+5;
ll n,q,a[mxn];

struct two
{
   ll l,r,sum,ans;
};
two st[4*mxn];
two up(two a, two b)
{
   ll l=max(a.l,a.sum+b.l);
   ll r=max(b.r,b.sum+a.r);
   ll sum=a.sum+b.sum;
   ll ans=max(a.r+b.l,max(a.ans,b.ans));
   return {l,r,sum,ans};
}

void update(ll i, ll l, ll r, ll p, ll val)
{
   if(p>r||p<l) return ;
   if(l==r) {
      st[i]={val,val,val,val};
      return;
   }
   ll mid=(l+r)>>1;
   update(i<<1,l,mid,p,val);
   update(i<<1|1,mid+1,r,p,val);
   st[i]=up(st[i<<1],st[i<<1|1]);
}
two get(ll i, ll l, ll r, ll u, ll v)
{
   if(u>r||v<l) return {-oo,-oo,0,-oo};
   if(u<=l&&r<=v) return st[i];
   ll mid=(l+r)>>1;
   return up(get(i<<1,l,mid,u,v),get(i<<1|1,mid+1,r,u,v));
}
void solve()
{
   cin>>n>>q;
   for(ll i=1;i<=n;++i) {
      cin>>a[i];
      update(1,1,n,i,a[i]);
   }
   for(ll i=1;i<=q;++i) {
      ll p; cin>>p;
      update(1,1,n,p,-oo);
      cout<<get(1,1,n,1,n).ans<<'\n';
   }

}
int main()
{
   TL
   if(fopen(task".inp","r")) {
      freopen(task".inp","r",stdin);
      freopen(task".out","w",stdout);
   }
   solve();
}
/// JUST KEEP TRAINING




