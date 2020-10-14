#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "tomau"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=50005;
int n,m,deg[mxn],f[mxn][4];
char d[4]={'R','R','B','C'};
char ans[mxn];
vector<int> a[mxn],ord,dsk[mxn];
map<pii,int> stt;
void solve()
{
   cin>>n>>m;
   for(int i=1;i<=m;++i) {
      int u,v; cin>>u>>v;
      stt[{u,v}]=i;
      a[u].push_back(v);
      deg[v]++;
      bv[u]++;
      dsk[v].push_back(u);
   }
   deque<int> q;
   for(int i=1;i<=n;++i) {
      for(int j=1;j<=3;++j) {
         f[i][j]=2e9;
      }
   }
   for(int i=1;i<=n;++i)
   if(!deg[i]) {
      q.push_back(i);
      f[i][1]=f[i][2]=f[i][3]=0;
   }
   while(!q.empty()) {
      int u=q.front();
      q.pop_front();
      ord.push_back(u);
      for(int v:a[u]) {
         --deg[v];
         if(!deg[v]) q.push_back(v);
      }
   }
   for(int i:ord) cout<<i<<' ';
   cout<<'\n';
   for(int u=1;u<=n;++u) {
      for(int v:a[u])
      for(int c=1;c<=3;++c) {
         f[v][c]=min(f[v][c],f[u][c]+1);
         for(int j=1;j<=3;++j)
            if(j!=c) f[v][c]=min(f[v][c],1);
      }
   }

}
int main()
{
   TL
   freopen(task".inp","r",stdin);
   freopen(task".out","w",stdout);
   solve();
}
/// JUST KEEP TRAINING




