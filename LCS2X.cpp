#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "lcs2x"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1505;
int a[mxn],b[mxn],n,m,f[mxn][mxn];

void solve()
{
   cin>>n>>m;
   for(int i=1;i<=n;++i) cin>>a[i];
   for(int i=1;i<=m;++i) cin>>b[i];

   for(int i=1;i<=n;++i)
      for(int j=1;j<=m;++j) f[i][j]=0;

   int ans=0;
   for(int i=1;i<=n;++i) {
      int best=0;
      for(int j=1;j<=m;++j) {
         f[i][j]=f[i-1][j];
         if(a[i]==b[j]) f[i][j]=max(f[i][j],best+1);
         if(a[i]>=2*b[j]) best=max(best,f[i-1][j]);
         ans=max(ans,f[i][j]);
      }
   }
   cout<<ans<<'\n';
}
int main()
{
   TL
   if(fopen(task".inp","r")) {
      freopen(task".inp","r",stdin);
      freopen(task".out","w",stdout);
   }
   int t;
   cin>>t;
   while(t--) solve();
}
/// JUST KEEP TRAINING




