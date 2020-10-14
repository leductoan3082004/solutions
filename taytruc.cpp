#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "taytruc"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=10005;
int n,k,a[mxn];
ll dp[mxn][505][3];

void solve() {
  cin >> n >> k;
  for(int i=1;i<=n;++i) {
    cin >> a[i];
  }
  for(int i=0;i<=n;++i) {
    for(int j=0;j<=k+5;++j) {
      dp[i][j][0]=dp[i][j][1]=-1e15;
    }
  }
  dp[0][0][0]=0;
  ///dp[i][j][0] di den i va lay j holo ,hien tai la ko co ho lo
  ///dp[i][j][1] di den i va lay j holo, hien tai co ho lo
  for(int i=1;i<=n;++i) {
    for(int j=0;j<=k;++j) {
      if(j>0) dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-1][1]+a[i]);
      if(j==1) dp[i][1][1]=max(dp[i][1][1],dp[i-1][0][0]+a[i]);
      dp[i][j][0]=max(dp[i-1][j+1][0],dp[i-1][j+1][1]);
      dp[i][0][0]=max(dp[i-1][0][0],dp[i][0][0]);
    }
  }
//  for(int i=0;i<=n;++i) {
//    for(int j=0;j<=k;++j) {
//      cout << dp[i][j][0] << ' ' << dp[i][j][1] << "|| ";
//    }
//    cout << endl;
//  }
  cout << dp[n][0][0];
}
int main() {
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.

