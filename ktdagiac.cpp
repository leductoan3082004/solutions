#include<bits/stdc++.h>

using namespace std;

#define task "ktdagiac"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=105;
pii a[mxn];
int n,st[mxn];
int s(pii a, pii b, pii c)
{
  return (a.fi-b.fi)*(a.se+b.se)+(b.fi-c.fi)*(b.se+c.se)+(c.fi-a.fi)*(c.se+a.se);
}
bool cmp(pii A, pii B)
{
  return s(a[1],A,B)>=0;
}
void solve()
{
  cin>>n;
  for(int i=1;i<=n;++i) {
    cin>>a[i].fi>>a[i].se;
  }
  a[n+1]=a[1];
  a[n+2]=a[2];
  int ok1=1,ok2=1;
  for(int i=1;i<=n;++i) {
    if(s(a[i],a[i+1],a[i+2])>0) ok1&=1;
    else ok1&=0;
  }
  for(int i=1;i<=n;++i) {
    if(s(a[i],a[i+1],a[i+2])<0) ok2&=1;
    else ok2&=0;
  }
  cout<<(ok1||ok2)<<endl;
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  int t; cin>>t;
  while(t--)solve();
}




