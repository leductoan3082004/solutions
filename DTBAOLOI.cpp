#include<bits/stdc++.h>

using namespace std;

#define task "dtbaoloi"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1005;
pii a[mxn];
int n,s[mxn];
int S(pii a, pii b, pii c)
{
//  cout<<a.first<<' '<<a.second<<endl;
//  cout<<b.first<<' '<<b.second<<endl;
//  cout<<c.first<<' '<<c.second<<endl;
  int ans=(a.first-b.first)*(a.second+b.second)+(b.first-c.first)*(b.second+c.second)
  +(c.first-a.first)*(c.second+a.second);
  return ans;
}
bool cmp(pii A, pii B)
{
  return (S(a[1],A,B)>=0);
}
void solve()
{
  cin>>n;
  for(int i=1;i<=n;++i) cin>>a[i].first>>a[i].second;
  int id=1;
  for(int i=2;i<=n;++i) {
    if (a[i].first<a[id].first) id=i;
  }
  swap(a[id],a[1]);
  sort(a+2,a+n+1,cmp);
  int top=0;
  for(int i=1;i<=n;++i) {
    while(top>=2&&S(a[s[top]],a[s[top-1]],a[i])>0) --top;
    s[++top]=i;
  }
  s[top+1]=s[1];
  ll ans=0;
  for(int i=1;i<=top;++i) {
    ans+=(a[s[i]].first-a[s[i+1]].first)*(a[s[i]].second+a[s[i+1]].second);
  }
  if(ans%2==0) cout<<ans/2<<".0000";
  else cout<<ans/2<<".5000";
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}


