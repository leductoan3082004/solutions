#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "baric"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=105;
int n,e,a[mxn];
ll L[mxn], R[mxn],f[mxn][mxn],dp[mxn][mxn];
void solve()
{
   cin>>n>>e;
   for(int i=1;i<=n;++i) cin>>a[i];

   for(int i=1;i<=n;++i) {
      for(int j=1;j<i;++j) {
         L[i]+=2*abs(a[i]-a[j]);
      }
   }
   for(int i=n;i>=1;--i) {
      for(int j=n;j>i;--j) {
         R[i]+=2*abs(a[i]-a[j]);
      }
   }
   for(int i=1;i<=n;++i) {
      for(int j=1;j<=n;++j) {
         for(int k=i+1;k<j;++k) f[i][j]+=abs(2*a[k]-(a[i]+a[j]));
      }
   }
   for(int i=1;i<=n;++i) {
      for(int j=1;j<=n;++j) {
         dp[i][j]=1e15;
      }
   }
   for(int i=1;i<=n;++i) dp[i][i]=0;

   for(int len=2;len<=n;++len) {
      for(int i=1;i<=n;++i) {
         int j=i+len-1;
         if(j>n) break;
         for(int k=i;k<=j;++k) {
            dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j])
         }
      }
   }
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




