#include<bits/stdc++.h>

using namespace std;

#define task "dulich"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=300;
int n,m,q,dd[mxn];
ll w[mxn][mxn],ans[mxn][mxn];
pii a[mxn],c[mxn];
void solve()
{
  cin>>n>>m>>q;
  for(int i=1;i<=n;++i) {
    cin>>c[i].first;
    c[i].second=i;
  }
  sort(c+1,c+n+1);
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=n;++j) {
      w[i][j]=2e9;
      ans[i][j]=2e9;
    }
  }
  for(int i=1;i<=m;++i) {
    int u,v,cost;
    cin>>u>>v>>cost;
    w[u][v]=cost;
    w[v][u]=cost;
  }
  for(int t=1;t<=n;++t) {
    int k=c[t].second;
    int val=c[t].first;
    dd[k]=1;
    for(int i=1;i<=n;++i) {
      for(int j=1;j<=n;++j) {
        if(dd[i]&&dd[j])
          w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
      }
    }
    for(int i=1;i<=n;++i) {
      for(int j=1;j<=n;++j) {
        if (dd[i]&&dd[j])
          w[i][j]=min(w[i][j],w[i][j]+w[j][k]);
      }
    }
    for(int i=1;i<=n;++i) {
      for(int j=1;j<=n;++j) {
        if(dd[i]&&dd[j])
        ans[i][j]=min(ans[i][j],w[i][k]+w[k][j]+val);
      }
    }
  }
  while (q--) {
    int u,v;
    cin>>u>>v;
    cout<<ans[u][v]<<endl;
  }
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}



