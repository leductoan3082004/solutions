#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "display"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1005;
int n,m,n1,m1,k,a[mxn][mxn],f[mxn][mxn];
int res[mxn][mxn];
void solve() {

  cin >> n >> m;
  cin >> n1 >> m1;
  cin >> k;
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=m;++j) {
      cin >> a[i][j];
    }
  }
  int ans=0;
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=m;++j) {
      f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
      int cur=(f[i][j]+a[i][j])%k;
      res[i][j]=cur;
      if ((i>n-n1+1||j>m-m1+1)&&cur!=0) {
        cout << "IMPOSSIBLE";
        return;
      }
      res[i][j]=0;
      int need=(0-cur+k)%k;
      ans+=need;
      f[i][j]+=need;
      f[i+n1][j]-=need;
      f[i][m1+j]-=need;
      f[i+n1][j+m1]+=need;
    }
  }
  cout << ans;
}
int main() {
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.

