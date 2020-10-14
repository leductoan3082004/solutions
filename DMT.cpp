#include<bits/stdc++.h>

using namespace std;

#define task "DMT"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;

const int N=1e6+5,mxn=1e6+5;
int f[mxn];
vector<ll> p,q;

void sang()
{
  f[0]=1;
  f[1]=1;
  for(int i=2;i<=sqrt(N);++i) {
    if(!f[i]){
      int j=i*i;
      while(j<=N) {
        f[j]=1;
        j+=i;
      }
    }
  }
  for(int i=1;i<=N;++i) if(!f[i])p.push_back(i);
}
void solve()
{
  sang();
  q.push_back(6561);
  for(ll i:p) if(i!=3) q.push_back(9LL*i*i);
  sort(q.begin(),q.end());
  int t;
  cin>>t;
  while(t--) {
    ll a,b; cin>>a>>b;
    int l=lower_bound(q.begin(),q.end(),a)-q.begin();
    int r=upper_bound(q.begin(),q.end(),b)-q.begin()-1;
    cout<<r-l+1<<endl;
  }
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}



