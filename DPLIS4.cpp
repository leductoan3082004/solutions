#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "DPLIS4"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=100005;
int n;
vector<int> s;
pii a[mxn];

void solve()
{
   cin>>n;
   s.push_back(-1);
   for(int i=1;i<=n;++i) {
      cin>>a[i].fi>>a[i].se;
      s.push_back(a[i].fi);
      s.push_back(a[i].se);
   }
   sort(s.begin(),s.end());
   s.resize(unique(s.begin(),s.end())-s.begin());
   sort(a)
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




