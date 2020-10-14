#include<bits/stdc++.h>

using namespace std;

#define task "tours"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

const int mxn=1e5+5;
const ld eps=1e-6;
int a[mxn],b[mxn],n;
ll res1,res2,ans1,ans2;
ld ans=0;
bool check(ld m)
{
  vector<pair<ld,int>> q;
  q.clear();
  for(int i=1;i<=n;++i) {
    q.push_back({(ld)b[i]-(ld)m*a[i],i});
  }
  int ok=0;
  ld res=0;
  res1=0; res2=0;
  sort(q.begin(),q.end(),greater<pair<ld,int>>());
  for(int i=1;i<q.size();++i) {
    int pos1=q[i].second;
    int pos2=q[i-1].second;
    res1=res+
  }
  return ok;
}
void solve()
{
  cin>>n;
  for(int i=1;i<=n;++i) cin>>a[i];
  for(int i=1;i<=n;++i) cin>>b[i];
  ld l=0.00, r=1e14;
  while(l<=r) {
    ld mid=(l+r)/2.00;
    if(check(mid)) {
      l=mid+eps;
    }
    else r=mid-eps;
//  }
  ll ucln=__gcd(ans1,ans2);
  cout<<ans1<<' '<<ans2;
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}






