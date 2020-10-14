#include<bits/stdc++.h>

using namespace std;

#define task "seqgame"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=105;
int a[mxn],b[mxn],s[mxn],n,m,k;
void solve()
{
  cin>>n>>m>>k;
  for(int i=1;i<=n;++i) cin>>a[i];
  for(int i=1;i<=m;++i) cin>>b[i];
  for(int _=1;_<=k;++_) {
    int x; cin>>x;
    int ans=2e9;
    for(int i=1;i<=n;++i) {
      for(int j=1;j<=m;++j) {
        ans=min(ans,abs(x-a[i]-b[j]));
      }
    }
    cout<<ans<<'\n';
  }
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".ans","w",stdout);
  solve();
}



