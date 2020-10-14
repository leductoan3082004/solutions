#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "nksgame"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=100005;
int n,a[mxn],b[mxn];
void solve()
{
   cin>>n;
   for(int i=1;i<=n;++i) cin>>a[i];
   for(int i=1;i<=n;++i) cin>>b[i];
   sort(a+1,a+n+1);
   sort(b+1,b+n+1,greater<int>());
   int j=1;
   int ans=2e9;
   for(int i=1;i<=n;++i) {
      while(j<n&&abs(b[j+1]+a[i])<=abs(b[j]+a[i])) ++j;
      ans=min(ans,abs(a[i]+b[j]));
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
/// JUST KEEP TRAINING




