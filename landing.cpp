#include<bits/stdc++.h>

using namespace std;

#define task "landing"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<ll,ll> pii;

const ll mxn=1e5+5;
pii a[mxn];
ll n,k,x,ans1=0,ans2=-1;
ll pre[5];


bool check2(ll dist)
{
  ll cnt=0;
  for(ll i=1;i<=k;++i) pre[i]=-dist;
  for(ll i=1;i<=n;++i)
  {
    ll l=a[i].first, r=a[i].second, m=-1;
    for(ll j=1;j<=k;++j)
      if(pre[j]+dist<=r&&(m==-1||pre[j]+dist<=pre[m]+dist)) m=j;
    if(m==-1) continue;

    pre[m]=max(pre[m]+dist,l);
    ++cnt;
  }
  return (cnt==ans1);
}
void solve()
{
  cin>>n>>k>>x;
  for(ll i=1;i<=n;++i) cin>>a[i].first>>a[i].second;
  sort(a+1,a+n+1);
  for(ll i=1;i<=k;++i) pre[i]=-x;
  for(ll i=1;i<=n;++i)
  {
    ll l=a[i].first, r=a[i].second, m=-1;
    for(ll j=1;j<=k;++j)
      if(pre[j]+x<=r&&(m==-1||pre[j]+x<=pre[m]+x)) m=j;
    if(m==-1) continue;
    pre[m]=max(pre[m]+x,l);
    ++ans1;
  }
  ll l=x,r=1e15;
  while(l<=r)
  {
    ll mid=(l+r)>>1;
    if(check2(mid))
    {
      ans2=mid;
      l=mid+1;
    }
    else r=mid-1;
  }
  ans2=(ans2==1e15?-1:ans2);
  cout<<ans1<<' '<<ans2;
}
int main()
{
  TL
//  freopen(task".inp","r",stdin);
//  freopen(task".out","w",stdout);
  solve();
}





