#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "task"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1e5+5;
struct two {
  int x,w;
  ll e;
};
two a[mxn];
int n;
ll dp[mxn];
void solve() {
  cin >> n;
  for(int i=1;i<=n;++i) {
    cin >> a[i].x >> a[i].w >> a[i].e;
  }
  a[0].x=a[0].w=0;
  a[0].e=0LL;
  dp[0]=0;
  for(int i=1;i<=n;++i) {
    for(int j=0;j<i;++j) {
      ll cost=(ll)a[j].w*abs(a[i].x-a[j].x);
      if (dp[j]-cost>=0) dp[i]=max(dp[i],dp[j]-cost+a[i].e);
    }
  }
  cout << dp[n];
}
int main() {
  TL
//  freopen(task".inp","r",stdin);
//  freopen(task".out","w",stdout);
  solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.

