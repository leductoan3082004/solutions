#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "chutrinh"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<ll,ll> pii;

const ll mxn=1e5+5;
ll n,m,A,B;
vector<ll> a[mxn];
ll dd1[mxn],dd2[mxn];
void solve()
{
   cin>>n>>m>>A>>B;
   for(ll i=1;i<=m;++i) {
      ll u,v;
      cin>>u>>v;
      a[u].push_back(v);
      a[v].push_back(u);
   }
   for(ll v:a[A])
      if(v!=B) dd1[v]=1;
   for(ll v:a[B])
      if(v!=A) dd2[v]=1;
   ll ans=0;
   for(ll i=1;i<=n;++i)
      if(i!=A&&i!=B&&dd1[i]&&dd2[i]) ++ans;
   cout<<ans*(ans-1)/2;
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




