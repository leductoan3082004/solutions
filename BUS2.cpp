#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "BUS2"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1005;
int a[mxn][mxn],n,m,f[mxn][mxn];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
struct two
{
  int x,y,w;
};
struct cmp
{
  bool operator()(two a,two b)
  {
    return a.w>b.w;
  }
};
void solve()
{
  cin>>n>>m;
  for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j) cin>>a[i][j];
  priority_queue<two,vector<two>,cmp> q;
  for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j) f[i][j]=2e9;

  f[1][1]=(a[1][1]==0?1:0);
  q.push({1,1,f[1][1]});

  while(!q.empty())
  {
    two tmp=q.top(); q.pop();
    int x=tmp.x,y=tmp.y,len=tmp.w;
    if(f[x][y]<len) continue;
    for(int i=0;i<4;++i)
    {
      int u=dx[i]+x,v=dy[i]+y;
      if(!(u>=1&&u<=n&&v>=1&&v<=m)) continue;
      int st=a[u][v];
      int w=len+1;
      if(w%2==1)st=1-st;
      if(st==0)++w;
      if(f[u][v]>w)
      {
        f[u][v]=w;
        q.push({u,v,w});
      }
    }
  }
  cout<<f[n][m];
}
int main()
{
  TL
//  freopen(task".inp","r",stdin);
//  freopen(task".out","w",stdout);
  solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.

