#include<bits/stdc++.h>

using namespace std;

#define task "keoco"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=105;
int dp[3][mxn*505][mxn],a[mxn],n;
void solve()
{
  cin>>n;
  int sum=0;
  for(int i=1;i<=n;++i) {
    cin>>a[i];
    sum+=a[i];
  }
  int l=0,r=0,ans=2e9;
  dp[0][0][0]=1;
  for(int i=1;i<=n;++i) {
    for(int j=0;j<=(sum+1)/2;++j) {
      for(int k=0;k<=(n+1)/2;++k) {
        dp[1][j][k]=dp[0][j][k];
        if(j-a[i]>=0)
          dp[1][j][k]=max(dp[1][j][k],dp[0][j-a[i]][k-1]);
        if (abs(n-k*2)<=1&&dp[1][j][k]&&abs(sum-2*j)<ans) {
          ans=abs(sum-2*j);
          l=j;
          r=sum-j;
        }
      }
    }
    for(int j=0;j<=sum;++j) {
      for(int k=0;k<=n;++k) {
        dp[0][j][k]=dp[1][j][k];
        dp[1][j][k]=0;
      }
    }
  }
  cout<<l<<' '<<r;
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}



