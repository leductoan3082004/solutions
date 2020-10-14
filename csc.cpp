#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "csc"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=100005;
int a[mxn],n;
unordered_map<int,int> M[55];
void solve()
{
   cin>>n;
   for(int i=1;i<=n;++i) cin>>a[i];
   set<int> s;
   int ans=0;
   for(int i=1;i<=n;++i) {
      for(auto it=s.lower_bound(a[i]-50);it!=s.end();++it) {
         int k=*it;
         if(a[i]-k<=0) break;
         M[a[i]-k][a[i]]=max(M[a[i]-k][a[i]],M[a[i]-k][k]+1);
         ans=max(ans,M[a[i]-k][a[i]]);
      }
      s.insert(a[i]);
   }
   cout<<ans+1;
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




