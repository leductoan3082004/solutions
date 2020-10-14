#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "GAME929"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1e6+5;
int a[mxn],n;
ll dp[mxn][4];
void solve()
{
  cin>>n;
  for(int i=1;i<=n;++i) cin>>a[i];

  for(int i=0;i<=n;++i) {
    for(int j=0;j<=2;++j) {
      dp[i][j]=-1e15;
    }
  }
  dp[0][0]=dp[0][1]=dp[0][2]=0;
  for(int i=1;i<=n;++i) {
    dp[i][2]=max(dp[i-1][2],max(dp[i-1][1],dp[i-1][0]));
    dp[i][1]=max(dp[i-1][2]+a[i],dp[i][1]);
    dp[i][0]=max(dp[i][0],dp[i-1][1]+a[i]);
  }
  cout<<max(dp[n][0],max(dp[n][1],dp[n][2]));
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.


