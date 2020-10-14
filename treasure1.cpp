#include<bits/stdc++.h>

using namespace std;

#define task "treasure1"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1005;
int a[mxn][mxn],m,n,dd[mxn][mxn],h[mxn][mxn];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
struct two
{
  int x,y,len;
};
struct cmp
{
  bool operator()(const two &a, const two &b)
  {
    return a.len>b.len;
  }
};
void solve()
{
  cin>>n>>m;
  deque<pii> q;
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=m;++j) {
      cin>>a[i][j];
      if(a[i][j]==0) {
        q.push_back({i,j});
        dd[i][j]=1;
      }
    }
  }
  int X,Y,U,V;
  cin>>X>>Y>>U>>V;
  while(!q.empty()) {
    int x=q.front().first, y=q.front().second;
    q.pop_front();
    for(int i=0;i<4;++i) {
      int u=x+dx[i];
      int v=y+dy[i];
      if(!(u>=1&&u<=n&&v>=1&&v<=m)) continue;
      if(dd[u][v]||a[u][v]==0)continue;
      dd[u][v]=1;
      h[u][v]=h[x][y]+1;
      q.push_back({u,v});
    }
  }
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=m;++j) {
      a[i][j]=2e9;
    }
  }
  priority_queue<two,vector<two>,cmp> que;
  a[X][Y]=0;
  que.push({X,Y,a[X][Y]});
  while(!que.empty()) {
    int x=que.top().x, y=que.top().y, len=que.top().len;
    que.pop();
    if (a[x][y]<len) continue;
    for(int i=0;i<4;++i) {
      int u=dx[i]+x;
      int v=dy[i]+y;
      int w=max(len,h[u][v]);
      if (a[u][v]>w) {
        a[u][v]=w;
        que.push({u,v,w});
      }
    }
  }
  cout<<a[U][V];
}
int main()
{
  TL
//  freopen(task".inp","r",stdin);
//  freopen(task".out","w",stdout);
  solve();
}



