#include<bits/stdc++.h>

using namespace std;

#define task "activity862"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

void solve()
{
  ll m,n,k,a,b;
  cin>>m>>n>>k>>a>>b;
  ll ans=min(m/a,n/b);
  k-=(m-a*ans)+(n-b*ans);
  k=max(0LL,k);
  ans-=(k+a+b-1)/(a+b);
  cout<<ans<<'\n';
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  int t;
  cin>>t;
  while(t--)
  solve();
}



