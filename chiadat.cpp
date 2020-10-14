#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "chiadat"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=505;
int n, f[mxn][mxn];

int get(int u, int v, int x, int y)
{
  return f[x][y]-f[u-1][y]-f[x][v-1]+f[u-1][v-1];
}
void solve()
{
  cin >> n;
  for (int i=1;i<=n;++i) {
    for (int j=1;j<=n;++j) {
      cin >> f[i][j];
      f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
    }
  }
  int ans=2e9;
  for (int i=1;i<=n;++i) {
    for (int j=1;j<=n;++j) {
      int mn=get(1,1,i,j);
      int mx=get(1,1,i,j);
      mn=min(mn,get(1,j+1,i,n));
      mx=max(mx,get(1,j+1,i,n));
      mn=min(mn,get(i+1,1,n,j));
      mx=max(mx,get(i+1,1,n,j));
      mn=min(mn,get(i+1,j+1,n,n));
      mx=max(mx,get(i+1,j+1,n,n));
      ans=min(ans,mx-mn);
    }
  }
  cout << ans;
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.














