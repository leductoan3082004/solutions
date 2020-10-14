#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "liondance"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=4005;
int delta,n,m,a[mxn],b[mxn],f[mxn][mxn];
vector<pii> mx[mxn];

pii found(int r, int c)
{
   pii ans={0,0};
   for(pii i:mx[f[r][c]-1]) {
      if(abs(b[i.se]-b[c])<=delta&&i.fi<r&&i.se<c&&b[ans.se]<b[i.se]) ans=i;
   }
   return ans;
}
void solve()
{
   cin>>n>>delta;
   for(int i=1;i<=n;++i) cin>>a[i];
   for(int i=1;i<=n;++i) cin>>b[i];
   reverse(a+1,a+n+1);
   reverse(b+1,b+n+1);

   /// f[i][j] ton tai k<=i sao cho a[k]==b[j]
   /// CTTH: f[i][j]=max(f[i-1][j],f[i-1][k](k<=j)+1)
   int ans=0;
   for(int i=1;i<=n;++i) {
      int best=0;
      for(int j=1;j<=n;++j) {
         f[i][j]=f[i-1][j];
         if(a[i]==b[j]) f[i][j]=max(f[i][j],best+1);
         if(abs(a[i]-b[j])<=delta) best=max(best,f[i-1][j]);
         ans=max(ans,f[i][j]);
      }
   }
   for(int i=n;i>=1;--i) {
      for(int j=n;j>=1;--j) {
         if(a[i]==b[j])
         mx[f[i][j]].push_back({i,j});
      }
   }
   for(int i=1;i<=n;++i) sort(mx[i].begin(),mx[i].end(),greater<pii>());

   int r,c,val=-1;
   for(int i=n;i>=1;--i) {
      for(int j=n;j>=1;--j) {
         if(f[i][j]==ans&&a[i]==b[j]&&a[i]>val) {
            r=i;
            c=j;
            val=a[i];
         }
      }
   }
   vector<int> res;
   while(r>=1&&c>=1) {
      res.push_back(b[c]);
      pii k=found(r,c);
      r=k.fi; c=k.se;
   }
   cout<<ans<<'\n';
   for(int i:res) cout<<i<<' ';
}
int main()
{
   TL
   if(fopen(task".inp","r")) {
      freopen(task".inp","r",stdin);
      freopen(task".out","w",stdout);
   }
   solve();
}
/// JUST KEEP TRAINING




