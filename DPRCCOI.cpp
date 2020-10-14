#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "DPRCCOI"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<ll,ll> pii;

map<ll,ll> dp;

ll cal(ll x)
{
   if(x==0) return 0;
   if(dp.count(x)) return dp[x];
   return dp[x]=max(x,cal(x/2)+cal(x/3)+cal(x/4));
}
void solve()
{
   while(1) {
      int x=-1;
      cin>>x;
      if(x==-1) break;
      cout<<cal(x)<<'\n';
   }
}
int  main()
{
   TL
   if(fopen(task".inp","r")) {
      freopen(task".inp","r",stdin);
      freopen(task".out","w",stdout);
   }
   solve();
}
/// JUST KEEP TRAINING



