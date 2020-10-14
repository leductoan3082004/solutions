#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "voi"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=100005;
int n,st[4*mxn];
pii a[mxn];
vector<int> s;

void update(int i, int l, int r, int p, int val)
{
   if(p>r||p<l) return;
   if(l==r) {
      st[i]=max(st[i],val);
      return;
   }
   int mid=(l+r)>>1;
   update(i<<1,l,mid,p,val);
   update(i<<1|1,mid+1,r,p,val);
   st[i]=max(st[i<<1],st[i<<1|1]);
}
int get(int i, int l, int r, int u, int v)
{
   if(u>r||v<l) return 0;
   if(u<=l&&r<=v) return st[i];
   int mid=(l+r)>>1;
   return max(get(i<<1,l,mid,u,v),get(i<<1|1,mid+1,r,u,v));
}
bool cmp(pii a, pii b)
{
   if(a.fi!=b.fi) return a.fi<b.fi;
   else return a.se>b.se;
}
void solve()
{
   n=0;
   while(1) {
      ++n;
      cin>>a[n].fi>>a[n].se;
      if(a[n].fi==0) break;
      s.push_back(a[n].se);
   }
   --n;
   s.push_back(-1);
   sort(a+1,a+n+1,cmp);
   sort(s.begin(),s.end());
   s.resize(unique(s.begin(),s.end())-s.begin());
   int ans=0;

   for(int i=1;i<=n;++i) {
      int k=lower_bound(s.begin(),s.end(),a[i].se)-s.begin();
      int val=get(1,1,n,k,n)+1;
      ans=max(ans,val);
      update(1,1,n,k,val);
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




