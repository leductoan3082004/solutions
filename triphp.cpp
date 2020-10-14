#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "task"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1e5+5;
int q[mxn][30],h[mxn],n,ord[mxn],cnt;
vector<int> a[mxn];
void dfs(int u, int pre) {
  ord[u]=++cnt;
  for(int v:a[u]) {
    if (v==pre) continue;
    q[v][0]=u;
    h[v]=h[u]+1;
    dfs(v,u);
  }
}
void initLCA() {
  for(int j=1;j<=log2(n);++j) {
    for(int i=1;i<=n;++i) {
      q[i][j]=q[q[i][j-1]][j-1];
    }
  }
}
int LCA(int u, int v)
{
  if (h[u]<h[v]) swap(u,v);
  int k=log2(h[u]);
  for(int i=k;i>=0;--i) {
    if (h[u]-(1<<i)>=h[v]) u=q[u][i];
  }
  if (u==v) return u;
  for(int i=k;i>=0;--i) {
    if (q[u][i]&&q[u][i]!=q[v][i]) {
      u=q[u][i];
      v=q[v][i];
    }
  }
  return q[u][0];
}
void create() {
  dfs(1,1);
  initLCA();
}
bool cmp(int a, int b) {
  return ord[a]<ord[b];
}
void solve() {
  cin >> n;
  for(int i=1;i<n;++i) {
    int u,v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  create();
  for(int i=1;i<=n;++i) {
    vector<int> q;
    if (i!=1) q.push_back(1);
    for(int j=i;j<=n;j+=i) {
      q.push_back(j);
    }
    int ans=0;
    sort(q.begin(),q.end(),cmp);
//    for(int i:q) cout << i << ' ';
//    break;
    for(int i=1;i<q.size();++i) {
      int u=q[i];
      int v=q[i-1];
      ans+=h[u]+h[v]-2*h[LCA(u,v)];
    }
    ans+=h[q.back()];
    cout << ans << '\n';
  }
}
int main() {
  TL
//  freopen(task".inp","r",stdin);
//  freopen(task".out","w",stdout);
  solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.

