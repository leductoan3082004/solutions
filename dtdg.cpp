#include<bits/stdc++.h>

using namespace std;

#define task "dtdg"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1005;
int n;
pii a[mxn];
void solve()
{
  cin>>n;
  for(int i=1;i<=n;++i) {
    cin>>a[i].first>>a[i].second;
  }
  int ans=0;
  a[n+1]=a[1];
  for(int i=1;i<=n;++i) {
    ans+=(a[i].first-a[i+1].first)*(a[i].second+a[i+1].second);
  }
  ans=abs(ans);
  if(ans%2==0) cout<<ans/2<<".00";
  else cout<<ans/2<<".50";
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}



