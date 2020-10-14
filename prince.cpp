#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "prince"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=505;
ll dp[mxn][mxn],ans=0;
int n,a[mxn],b[mxn];
void solve() {
  cin >> n;
  for(int i=1;i<=n;++i) {
    cin >> a[i] >> b[i];
  }
  cin >> a[n+1];
  b[n+1]=0;
  for(int i=1;i<=n;++i) dp[0][i]=b[i];
  for(int i=1;i<=n+1;++i){
    for(int k=i+1;k<=n+1;++k) {
      for(int j=0;j<i;++j) {
        if(a[k]-a[i]<=a[i]-a[j]) dp[i][k]=max(dp[i][k],dp[j][i]+b[k]);
      }
    }
  }
  for(int i=0;i<=n;++i) ans=max(dp[i][n+1],ans);
  cout << ans;
}
int main() {
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.

