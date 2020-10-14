#include<bits/stdc++.h>

using namespace std;

#define task "hp"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=30005;

int n,a[mxn];
ll f[mxn],ans=0;
void solve()
{
  cin>>n;
  for(int i=1;i<=n;++i) {
    cin>>a[i];
    f[i]=f[i-1]+a[i];
  }
  for(int i=1;i<=n;++i) {
    ans+=1LL*f[i-1]*a[i];
  }
  cout<<ans;
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}




