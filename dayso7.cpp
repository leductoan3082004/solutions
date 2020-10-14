#include<bits/stdc++.h>

using namespace std;

#define task "dayso7"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=200005;
int n,a[mxn];
ll f[mxn],l[mxn],r[mxn],g[mxn];
void solve()
{
  cin>>n;
  for(int i=1;i<=n;++i) cin>>a[i];
  for(int i=3;i<=n;++i) {
    f[i]=a[i]+a[i-1]+a[i-2];
  }
  for(int i=3;i<=n;++i) {
    if(f[i-3]>0) f[i]+=f[i-3];
  }
  l[3]=f[3];
  for(int i=4;i<=n;++i) l[i]=max(l[i-1],f[i]);
  for(int i=n-2;i>=1;--i) {
    g[i]=a[i]+a[i+1]+a[i+2];
  }
  for(int i=n-2;i>=1;--i) {
    if(g[i+3]>0) g[i]+=g[i+3];
  }
  r[n-2]=g[n-2];
  for(int i=n-3;i>=1;--i) r[i]=max(r[i+1],g[i]);
  ll ans=-1e15;
  for(int i=3;i<=n-3;++i) ans=max(ans,l[i]+r[i+1]);
  cout<<ans;
}
int main()
{
  TL
//  freopen(task".inp","r",stdin);
//  freopen(task".out","w",stdout);
  solve();
}




