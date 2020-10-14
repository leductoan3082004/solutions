#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "golf"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;
template <typename T>
inline void read(T& x)
{
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' | c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}
const int mxn=505;
int n,m,a[mxn][mxn],d[mxn][mxn];
vector<pii> goal;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
struct two
{
  int x,y,w;
};
struct cmp
{
  bool operator() (const two &a, const two &b)
  {
    return a.w>b.w;
  }
};
void dijkstra(int x, int y)
{
  priority_queue<two,vector<two>,cmp> q;
  for (int i=1;i<=n;++i) {
    for (int j=1;j<=m;++j) {
      d[i][j]=2e9;
    }
  }
  d[x][y]=0;
  q.push({x,y,0});
  while (!q.empty()) {
    x=q.top().x;
    y=q.top().y;
    int len=q.top().w;
    q.pop();
    if (len>d[x][y]) continue;
    for (int i=0;i<4;++i) {
      int u=x+dx[i], v=y+dy[i];
      if (!(u>=1&&u<=n&&v>=1&&v<=m)) continue;
      int w=max(abs(a[u][v]-a[x][y]),len);
      if (d[u][v]>w) {
        d[u][v]=w;
        q.push({u,v,w});
      }
    }
  }
}
void solve()
{
  read(n); read(m);
  for (int i=1;i<=n;++i) {
    for (int j=1;j<=m;++j) {
      read(a[i][j]);
    }
  }
  for (int i=1;i<=n;++i) {
    for (int j=1;j<=m;++j) {
      int x; read(x);
      if (x==1) {
        goal.push_back({i,j});
      }
    }
  }
  dijkstra(goal[0].first,goal[0].second);
  int ans=0;
  for (int i=0;i<goal.size();++i) {
    int u=goal[i].first;
    int v=goal[i].second;
    ans=max(ans,d[u][v]) ;
  }
  write(ans);
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.














