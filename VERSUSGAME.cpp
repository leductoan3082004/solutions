#include<bits/stdc++.h>

using namespace std;

#define task "versusgame"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1e6+5;
int n,dp[mxn][8];
int d[]={5,4,4,3,1,10};
void solve()
{
  for(int i=1;i<=1e6;++i)
    for(int j=0;j<6;++j) dp[i][j]=2e9;
  for(int i=1;i<=1e6;++i) {
    for(int j=0;j<6;++j) {
      if(j==0&&i>=d[5]) dp[i][5]=min(dp[i][5],dp[i-d[5]][j]+1);
      if(j==1&&i>=d[0]) dp[i][0]=min(dp[i][0],dp[i-d[0]][j]+1);
      if(j==2&&i>=d[4]) dp[i][4]=min(dp[i][4],dp[i-d[4]][j]+1);
      if(j!=0&&j!=1&&j!=2)
        for(int k=0;k<6;++k)
          if(i-d[k]>=0)
          dp[i][k]=min(dp[i][k],dp[i-d[k]][j]+1);
    }
  }
  int t;
  cin>>t;
  while(t--) {
    int ans=2e9;
    int n;
    cin>>n;
    for(int i=0;i<=5;++i)
      if(i!=0&&i!=1&&i!=2) ans=min(ans,dp[n][i]);
    cout<<ans<<endl;
  }
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}


