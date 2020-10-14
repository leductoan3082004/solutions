#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "donuoc1258"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=25;
int n,k,dp[mxn][(1<<20)+5];
int a[mxn][mxn];

void solve() {
  cin >> n >> k;
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=n;++j) {
      cin >> a[i][j];
    }
  }
  for(int i=0;i<=n;++i) {
    for(int j=0;j<=(1<<n);++j) {
      dp[i][j]=2e9;
    }
  }
  for(int i=1;i<=n;++i) dp[0][1<<(i-1)]=0;

  for(int mask=1; mask<(1<<n);++mask) {
    int cnt=0;
    for(int i=0;i<n;++i)
      if ((mask>>i)&1) ++cnt;
    if (cnt>k) continue;
    for(int i=1;i<=n;++i) {
      for(int j=1;j<=n;++j) {
        if ((mask>>(j-1))&1) dp[i][mask]=min(dp[i][mask],dp[i-1][mask]+a[i][j]);
      }
    }
  }
  int ans=2e9;
  for(int mask=1; mask<(1<<n);++mask) {
    int cnt=0;
    for(int i=0;i<n;++i)
      if ((mask>>i)&1) ++cnt;
    if (cnt>k) continue;
    ans=min(ans,dp[n][mask]);
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

