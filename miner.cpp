#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "miner"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=505;
int n,m,k,a[mxn][mxn],f[mxn][mxn];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
struct two {
  int x,y,val,s;
};
struct cmp {
  bool operator() (const two &a,const two &b) {
    return a.val<b.val;
  }
};
void solve() {

  cin >> n >> m >> k;
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=m;++j) {
      cin >> a[i][j];
    }
  }
  priority_queue<two,vector<two>,cmp> q;
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=m;++j) {
      q.push({i,j,a[i][j],0});
    }
  }
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=m;++j) {
      f[i][j]=a[i][j];
    }
  }
  while(!q.empty()) {
    two tmp=q.top(); q.pop();
    int x=tmp.x, y=tmp.y, len=tmp.val, s=tmp.s;
//    if (x==2&&y==2) cout << s << ' ' << len << '\n';
    if (s==k) continue;
    for(int i=0;i<4;++i) {
      int u=x+dx[i];
      int v=y+dy[i];
      if (!(u>=1&&u<=n&&v>=1&&v<=m)) continue;
      int mx=max(a[u][v],len);
      q.push({u,v,len,s+1});
      if (f[u][v]<mx) {
        f[u][v]=mx;
        q.push({u,v,f[u][v],s+1});
      }
    }
  }
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=m;++j) {
      cout << f[i][j] << ' ';
    }
    cout << '\n';
  }
}
int main() {
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.

