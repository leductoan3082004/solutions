#include<bits/stdc++.h>

using namespace std;

#define task "dtd"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;

pii a[5];

int S(pii a, pii b, pii c)
{
  return (a.fi-b.fi)*(a.se+b.se)+(b.fi-c.fi)*(b.se+c.se)+(c.fi-a.fi)*(c.se+a.se);
}
void solve()
{
  cin>>a[1].fi>>a[1].se>>a[2].fi>>a[2].se>>a[3].fi>>a[3].se;
  a[4]={1001,1001};
  int ok=0;
  if(S(a[1],a[3],a[4])>=0&&S(a[2],a[3],a[4])<=0&&S(a[1],a[2],a[3])==0) ok=1;
  if(S(a[1],a[3],a[4])<=0&&S(a[2],a[3],a[4])>=0&&S(a[1],a[2],a[3])==0) ok=1;
  cout<<ok<<endl;

}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  int t;
  cin>>t;
  while(t--)solve();
}




