#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "banhkeo"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1005;
int p[mxn],n,m,mn=2e9,dd[mxn],k;
vector<pii> a[mxn];

void dfs(int u) {
  dd[u]=1;
  for (int i=0;i<a[u].size();++i) {
    int v=a[u][i].first;
    int w=a[u][i].second;
    if (dd[v]||mn>w) continue;
    else dfs(v);
  }
}
void solve()
{
  cin >> n >> m >> k;
  for (int i=1;i<=k;++i) {
    cin >> p[i];
    mn=min(mn,p[i]);
  }
//  cout << mn << endl;
  for (int i=1;i<=m;++i) {
    int u,v,w;
    cin >> u >> v >> w;
    a[u].push_back({v,w});
    a[v].push_back({u,w});
  }
  int ans = 0;
  for (int i=1;i<=n;++i) {
    if (!dd[i]) {
      dfs(i);
      ++ans;
    }
  }
  cout << ans << endl;
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.














