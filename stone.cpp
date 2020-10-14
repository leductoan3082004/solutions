#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "stone"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<ll,ll> pii;

ll a[15],b[15];
void solve()
{
   ll ans=0;
   for(ll i=1;i<=14;++i) {
      cin>>a[i];
   }

   for(ll i=1;i<=14;++i) {
      for(ll j=1;j<=14;++j) b[j]=a[j];
      ll k=b[i]; b[i]=0;
      if(k==0) continue;
      for(ll j=i+1;j<=14;++j) {
         if(k==0) break;
         k-=1;
         b[j]++;
      }
      for(ll j=1;j<=14;++j) b[j]+=k/14;
      k%=14;
      for(ll j=1;j<=14;++j) {
         if(k==0) break;
         k-=1;
         b[j]++;
      }
      ll sum=0;
      for(ll j=1;j<=14;++j) sum+=(b[j]&1?0:b[j]);
      ans=max(ans,sum);
   }
   cout<<ans;
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




