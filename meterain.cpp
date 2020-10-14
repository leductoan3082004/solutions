#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "meterain"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define rep(i,a,b) for(ll i=(ll)a;i<=(ll)b;++i)
#define rep_(i,a,b) for(ll i=(ll)a;i>=(ll)b;--i)
#define fi first
#define se second

typedef long long ll;
typedef pair<ll,ll> pii;

const ll mxn=5005;
pii a[mxn];
ll n,m;
ll S(pii a, pii b, pii c)
{
  return (a.fi-b.fi)*(a.se+b.se)+(b.fi-c.fi)*(b.se+c.se)+(c.fi-a.fi)*(c.se+a.se);
}
void solve()
{
  cin>>n;
  rep(i,1,n) cin>>a[i].fi>>a[i].se;
  a[n+1]=a[1];
  ll s=0;
  rep(i,1,n) s+=(a[i].fi-a[i+1].fi)*(a[i].se+a[i+1].se);
  cin>>m;
  rep(i,1,m)
  {
    pii k;
    cin>>k.fi>>k.se;
    ll ans=0,ok=1;
    rep(j,1,n)
    {
      ans+=abs(S(a[j],a[j+1],k));
      if(abs(S(a[j],a[j+1],k))==0)
      {
        ok=0;
        break;
      }
    }
    cout<<((s==ans&&ok)?"YES":"NO");
    cout<<'\n';
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
