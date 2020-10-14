#include<bits/stdc++.h>

using namespace std;

#define task "gallery"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=205;
int n,k,a[mxn][3],dp[mxn][mxn][5];
void solve()
{
  cin>>n>>k;
  int sum=0;
  for(int i=1;i<=n;++i) {
    cin>>a[i][1]>>a[i][2];
    sum+=a[i][1]+a[i][2];
  }

  for(int i=0;i<=n;++i) {
    for(int j=0;j<=k;++j) {
      dp[i][j][1]=dp[i][j][2]=2e9;
    }
  }
  dp[0][0][1]=0;
  dp[0][0][2]=0;
  for(int i=1;i<=n;++i) {
    for(int j=0;j<=k;++j) {
      dp[i][j][1]=dp[i-1][j][1];
      dp[i][j][2]=dp[i-1][j][2];
      if(j>0) dp[i][j][1]=min(dp[i][j][1],dp[i-1][j-1][1]+a[i][1]);
      if(j>0) dp[i][j][2]=min(dp[i][j][2],dp[i-1][j-1][2]+a[i][2]);
      if(i>=2&&j>=1) dp[i][j][1]=min(dp[i][j][1],dp[i-2][j-1][2]+a[i][1]);
      if(i>=2&&j>=1) dp[i][j][2]=min(dp[i][j][2],dp[i-2][j-1][1]+a[i][2]);
    }
  }
  cout<<sum-min(dp[n][k][1],dp[n][k][2]);
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}




