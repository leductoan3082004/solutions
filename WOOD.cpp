#include<bits/stdc++.h>

using namespace std;

#define task "wood"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1005,mxk=1e5+5,mod=1e9+7;
int a[mxn],k,n,dp[mxk];

void add(int &a, int b)
{
  a=(a+b)%mod;
}
void solve()
{
  cin>>k>>n;
  for(int i=1;i<=n;++i) {
    cin>>a[i];
  }
  dp[0]=1;
  for(int j=0;j<=k;++j) {
    for(int i=1;i<=n;++i) {
      if(j-a[i]>=0) add(dp[j],dp[j-a[i]]);
    }
  }
  cout<<dp[k];
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}






