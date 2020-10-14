#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "donuoc1258"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=25;
int n,k,dp[1<<20+5];
int a[mxn][mxn];
void solve() {
  cin >> n >> k;
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=n;++j) {
      cin >> a[i][j];
    }
  }
  dp[0]=0;
  int ans=2e9;
  for(int mask=1;mask<(1<<n);++mask) {
    int cnt=0;
    for(int i=1;i<=n;++i) {
      if ((mask>>(i-1))&1) ++cnt;
    }
    dp[mask]=2e9;
    for(int i=1;i<=n;++i)
    if ((mask>>(i-1))&1) {
      int m=mask^(1<<(i-1));
      for(int j=1;j<=n;++j)
        if ((m>>(j-1)&1)==0&&j!=i) {
          dp[mask]=min(dp[mask],dp[m]+a[j][i]);
        }
    }
    if (cnt==k) ans=min(ans,dp[mask]);
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


