#include<bits/stdc++.h>

using namespace std;

#define task "LCSUB"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1e5+5;
int a[mxn],n,k;
void solve()
{
  cin>>n>>k;
  for(int i=1;i<=k;++i) {
    int x;
    cin>>x;
    a[x]=1;
  }
  for(int i=1;i<=n;++i) {
    if(a[i]==1) f[i]=f[i-1]+1;
    else f[i]=0;
  }
  for(int i=n;i>=1;--i) {
    if(a[i]==1) g[i]=g[i+1]+1;
    else g[i]=0;
  }
  int dem=0;
  for(int i=1;i<=n;++i) {
    if(a[i]==0&&a[i-1]!=0)
  }
}
int main()
{
  TL
//  freopen(task".inp","r",stdin);
//  freopen(task".out","w",stdout);
  solve();
}



