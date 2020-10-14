#include<bits/stdc++.h>

using namespace std;

#define task "quangcao"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=100;
int a[15][mxn],b[15][mxn],n,m;
int ans=0;

void calc(int mask)
{
  int cnt=0;
  for(int i=1;i<=n;++i) {
    if((mask>>i)&1) b[i][j]=1-a[i][j];
    else b[i][j]=a[i][j];
    if(b[i][j]) ++cnt;
  }
  for(int j=1;j<=m;++j) {

  }
}
void solve()
{
  cin>>n>>m;
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=m;++j) {
      cin>>a[i][j];
    }
  }

  for(int mask=0;mask<(1<<n);++mask) {
    calc(mask);
  }
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}






