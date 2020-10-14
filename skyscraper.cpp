#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "skyscraper"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=20;
int a[mxn],n,w,dp[mxn][262200];
int BIT(int n,int i) {
  return (n>>i)&1;
}
void calc(int mask) {
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=n;++j) {
      if (!BIT(mask,j-1)) continue;
      int pre=mask^(1<<(j-1));
      dp[i][mask]=min(dp[i][mask],dp[i][pre]+a[j]);
      dp[i][mask]=min(dp[i][mask],min(dp[i-1][pre],a[j]));
    }
  }
}
void solve() {
  cin >> n >> w;
  for(int i=1;i<=n;++i) cin >> a[i];

  for(int i=0;i<=n;++i) {
    for(int mask=0;mask<=(1<<n);++mask) {
      dp[i][mask]=2e9;
    }
  }
  for(int i=1;i<=n;++i) dp[1][1<<(i-1)]=a[i];

  for(int mask=1;mask<(1<<n);++mask) {
    calc(mask);
  }
  for(int i=1;i<=n;++i) {
    for(int mask=0;mask<(1<<n);++mask) {
      cout << dp[i][mask] << ' ';
    }
    cout << endl;
  }
  cout << dp[3][(1<<n)-1] << '\n';
}
int main() {
  TL
//  freopen(task".inp","r",stdin);
//  freopen(task".out","w",stdout);
  solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.

