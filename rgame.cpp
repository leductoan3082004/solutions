#include<bits/stdc++.h>

using namespace std;

#define task "rgame"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=300005;
int a[mxn],n,dd[mxn];
void solve()
{
  cin>>n;
  for(int i=1;i<=n;++i) {
    cin>>a[i];
  }
  ll ans=0,tmp1=0,tmp2=0;
  sort(a+1,a+n+1,greater<int>());
  for(int i=2;i<=n;++i) {
    if(a[i]==a[i-1]&&!dd[i]&&!dd[i-1]) {
      tmp1=a[i];
      dd[i]=1;
      dd[i-1]=1;
      break;
    }
  }
  for(int i=1;i<=n;++i) {
    if(a[i]==a[i-1]&&!dd[i]&&!dd[i-1]) {
      tmp2=a[i];
      break;
    }
  }
  ans=tmp1*tmp2;
  for(int i=0;i<=n;++i) dd[i]=0;
  cout<<((ans!=0)?ans:(-1))<<'\n';
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  int t;
  cin>>t;
  while(t--)
  solve();
}




