#include<bits/stdc++.h>

using namespace std;

#define task "hana2"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=205;
const int mod=1e7;
int n,m,a[mxn][mxn],dp[mxn][mxn][16];
void add(int &a, int b)
{
  a=(a+b)%mod;
}
void solve()
{
  cin>>n>>m;
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=m;++j) {
      cin>>a[i][j];
    }
  }
  dp[1][1][0]=1;
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=m;++j) {
      if(i==1&&j==1) continue;
      if(a[i][j]==-1) continue;
      for(int mask=0;mask<(1<<3);++mask) {
        int new_mask=mask;
        if(!(i==n&&j==m)) new_mask=mask|(1<<(a[i][j]-1));
        add(dp[i][j][new_mask],dp[i-1][j][mask]);
        add(dp[i][j][new_mask],dp[i][j-1][mask]);
      }
    }
  }
  int ans=0;
  for(int mask=1;mask<(1<<3);++mask){
    int dem=0;
    for(int i=0;i<3;++i)
      if((mask>>i)&1) ++dem;
    if(dem>=2) add(ans,dp[n][m][mask]);
  }
  cout<<ans;
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}




