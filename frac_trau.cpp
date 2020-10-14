#include<bits/stdc++.h>

using namespace std;

#define task "frac"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<ll,ll> pii;

ll m,n,ans;
void solve()
{
  cin>>m>>n;
  ll l=m+1, r=m+(m-1);
  for(ll q=1;q<n;++q) {
    ll mau=n+q;
    ans+=r/mau-(l-1)/mau;
  }
  cout<<ans;
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".ans","w",stdout);
  solve();
}






