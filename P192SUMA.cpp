#include<bits/stdc++.h>

using namespace std;

#define task "P192SUMA"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<ll,ll> pii;

const ll mxn=1e6+5;
ll n,a[mxn],d;
void solve()
{
  cin>>n>>d;
  for(ll i=1;i<=n;++i) {
    cin>>a[i];
  }
  ll res=0;
  for(ll i=2;i<=n;++i) {
    if(a[i-1]<a[i]) continue;
    if(a[i]==a[i-1]) {
      ++res;
      a[i]+=d;
      continue;
    }
    res+=(a[i-1]-a[i]+d-1)/d;
    a[i]+=(a[i-1]-a[i]+d-1)/d*d;
  }
  cout<<res;
}
int main()
{
  TL
//  freopen(task".inp","r",stdin);
//  freopen(task".out","w",stdout);
  solve();
}






