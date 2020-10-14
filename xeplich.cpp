#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "xeplich"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=105;
int n,k,a[mxn][mxn],dp[mxn][mxn];
void solve()
{
  cin >> n >> k;
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=k;++j) {
      cin >> a[i][j];
    }
  }
  dp[0][0]=0;
  for(int i=1;i<=n;++i) dp[i][i]=dp[i-1][i-1]+a[i][i];
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=k;++j) {
      if (i==j) continue;
      dp[i][j]=max(dp[i-1][j-1]+a[i][j],dp[i][j]);
      dp[i][j]=max(dp[i][j-1],dp[i][j]);
    }
  }
  cout << dp[n][k];
}
int main()
{
  TL
//  freopen(task".inp","r",stdin);
//  freopen(task".out","w",stdout);
  solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.














