#include<bits/stdc++.h>

using namespace std;

#define task "vector"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1e5+5;
int a[mxn][30],n,m,f[mxn],dp[mxn];

int lower(int u, int v)
{
  for(int i=1;i<=m;++i) {
    if(a[u][i]>=a[v][i]) return 0;
  }
  return 1;
}
void solve1()
{
  int ans=0;
  for(int i=1;i<=n;++i) dp[i]=1;
  for(int i=1;i<=n;++i) {
    for(int j=1;j<i;++j) {
      if(lower(j,i)) dp[i]=max(dp[i],dp[j]+1);
    }
    ans=max(ans,dp[i]);
  }
  cout<<ans;
}
void solve2()
{
  int dem=0;
  for(int i=1;i<=n;++i) {
    int l=1,r=dem,k=0;
    while(l<=r) {
      int mid=(l+r)>>1;
      if(lower(f[mid],i)) {
        l=mid+1;
        k=mid;
      }
      else r=mid-1;
    }
    f[++k]=i;
    dem=max(dem,k);
  }
  cout<<dem<<'\n';
}
void nhap()
{
  cin>>n>>m;
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=m;++j) {
      cin>>a[i][j];
    }
    sort(a[i]+1,a[i]+m+1);
  }
  if(m==1) solve2();
  else solve1();
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  nhap();
}





