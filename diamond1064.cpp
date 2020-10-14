#include<bits/stdc++.h>

using namespace std;

#define task "diamond1064"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

const ld eps=1e-5;
const ll mxn=50005;
ll res1,res2,ans1,ans2,n,k,a[mxn],b[mxn];
bool check(ld m)
{
  vector<pair<ld,ll>> tmp;
  tmp.clear();
  for(ll i=1;i<=n;++i) {
    ld tam=(ld)a[i]-(ld)b[i]*m;
    tmp.push_back({tam,i});
  }
  sort(tmp.begin(),tmp.end(),greater<pair<ld,ll>>());
  ld ans=0;
  ans1=0; ans2=0;
  for(ll i=0;i<k;++i) {
    ll pos=tmp[i].second;
    ans+=tmp[i].first;
    ans1+=a[pos];
    ans2+=b[pos];
  }
  return (ans>=0.00);
}
void solve()
{
  cin>>n>>k;
  for(ll i=1;i<=n;++i) cin>>a[i]>>b[i];
  ld l=0.00, r=1e11;
  while(l<=r) {
    ld mid=(l+r)/2.00;
    if(check(mid)) {
      l=mid+eps;
      res1=ans1;
      res2=ans2;
    }
    else r=mid-eps;
  }
//  cout<<check(1.83333)<<endl;
  ll ucln=__gcd(res1,res2);
  cout<<res1/ucln<<' '<<res2/ucln;
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}






