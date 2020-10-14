#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "task"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1e5+5;
int a[mxn],f[mxn],n,l[mxn],r[mxn];
void solve() {
  cin >> n;
  for(int i=1;i<=n;++i) {
    cin >> a[i];
  }
  a[0]=-1;
  a[n+1]=-1;
  for(int i=1;i<=n;++i) {
    if (a[i]>a[i-1]) l[i]=l[i-1]+a[i];
    else l[i]=1;
  }
  for(int i=n;i>=1;--i) {
    if (a[i]>a[i+1]) r[i]=r[i+1]+a[i];
    else r[i]=1;
  }
  int q;
  cin >> q;
  while(q--) {
    int l,r;
    cin >> l >> r;

  }
}
int main() {
  TL
//  freopen(task".inp","r",stdin);
//  freopen(task".out","w",stdout);
  solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.














