#include<bits/stdc++.h>

using namespace std;

#define task "duha"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1005;
string s[mxn];
int n,m;
int f[5][2][mxn][mxn];
void solve()
{
  cin>>n>>m;
  for(int i=1;i<=n;++i) {
    cin>>s[i];
    s[i]=' '+s[i];
  }

  for(int i=1;i<=n;++i) {
    for(int j=1;j<=m;++j) {
      if(s[i][j]=='0') continue;
      f[1][0][i][j]=f[1][1][i][j-1]+1;
      f[1][1][i][j]=f[1][0][i-1][j]+1;
    }
  }
  for(int i=1;i<=n;++i) {
    for(int j=m;j>=1;--j) {
      if(s[i][j]=='0') continue;
      f[2][0][i][j]=f[2][1][i][j+1]+1;
      f[2][1][i][j]=f[2][0][i-1][j]+1;
    }
  }
  for(int i=n;i>=1;--i) {
    for(int j=m;j>=1;--j) {
      if(s[i][j]=='0') continue;
      f[3][0][i][j]=f[3][1][i][j+1]+1;
      f[3][1][i][j]=f[3][0][i+1][j]+1;
    }
  }
  for(int i=n;i>=1;--i) {
    for(int j=1;j<=m;++j) {
      if(s[i][j]=='0') continue;
      f[4][0][i][j]=f[4][1][i][j-1]+1;
      f[4][1][i][j]=f[4][0][i+1][j]+1;
    }
  }
  int ans=0;
  for(int i=1;i<=n;++i) {
    for(int j=1;j<=m;++j) {
      if(s[i][j]=='0') continue;
      ans=max(ans,f[1][0][i][j]+f[2][1][i][j]+f[3][0][i][j]+f[4][1][i][j]-3);
    }
  }
  cout<<ans;
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}




