#include<bits/stdc++.h>

using namespace std;

#define task "express"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1e5+5;
int n,k,a[mxn];
ll ans=0;
void solve()
{
  cin>>n>>k;
  for(int i=1;i<=n;++i) {
    cin>>a[i];
  }
  sort(a+1,a+n+1,greater<int>());
  for(int i=1;i<=k+1;++i) ans+=a[i];
  for(int i=k+2;i<=n;++i) ans-=a[i];
  cout<<ans;
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}



