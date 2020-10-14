#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "ntseq"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=100005,mod=1e9+7;
int a[mxn],n,num[mxn],len[mxn];
vector<int> s;
pii st[4*mxn];

pii up(pii a, pii b)
{
   if(a.fi!=b.fi) return max(a,b);
   else return {a.fi,(a.se+b.se)%mod};
}
void update(int i, int l, int r, int p, pii val)
{
   if(p>r||p<l) return;
   if(l==r) {
      st[i]=val;
      return;
   }
   int mid=(l+r)>>1;
   update(i<<1,l,mid,p,val);
   update(i<<1|1,mid+1,r,p,val);
   st[i]=up(st[i<<1],st[i<<1|1]);
}
pii get(int i, int l, int r, int u, int v)
{
   if(u>r||v<l) return {0,0};
   if(u<=l&&r<=v) return st[i];
   int mid=(l+r)>>1;
   return up(get(i<<1,l,mid,u,v),get(i<<1|1,mid+1,r,u,v));
}
void solve()
{
   cin>>n;
   s.push_back(-2e9);
   for(int i=1;i<=n;++i) {
      cin>>a[i];
      s.push_back(a[i]);
   }
   sort(s.begin(),s.end());
   s.resize(unique(s.begin(),s.end())-s.begin());

   for(int i=1;i<=n;++i) {
      int k=lower_bound(s.begin(),s.end(),a[i])-s.begin();
      pii tmp=get(1,1,n,1,k-1);
      if(tmp.se==0) {
         len[k]=1;
         ++num[k];
      }
      else if(len[k]<tmp.fi+1) {
         len[k]=tmp.fi+1;
         num[k]=tmp.se;
      }
      else if(tmp.fi+1==len[k]) num[k]=(num[k]+tmp.se)%mod;
      update(1,1,n,k,{len[k],num[k]});
   }
   cout<<st[1].se;
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




