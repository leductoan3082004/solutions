#include<bits/stdc++.h>

using namespace std;

#define task "bonus"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<ll,ll> pii;

const ll mxn=305;
ll n,k,a[mxn],dp[mxn][mxn][mxn];
void solve()
{
  cin>>n>>k;
  for(ll i=1;i<=n;++i) {
    cin>>a[i];
  }
  for(ll i=1;i<=k;++i) {
    for(ll len=1;len<=n;++len) {
      for(ll l=1;l<=n;++l) {
        ll r=l+len-1;
        if(r>n||len<2*i) break;
        dp[i][l][r]=max(dp[i-1][l+2][r]+abs(a[l]-a[l+1]),dp[i][l][r]);
        dp[i][l][r]=max(dp[i-1][l][r-2]+abs(a[r]-a[r-1]),dp[i][l][r]);
        dp[i][l][r]=max(dp[i][l][r],dp[i-1][l+1][r-1]+abs(a[r]-a[l]));
        dp[i][l][r]=max(dp[i][l+1][r],dp[i][l][r]);
        dp[i][l][r]=max(dp[i][l][r-1],dp[i][l][r]);
      }
    }
  }
  cout<<dp[k][1][n];
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}



