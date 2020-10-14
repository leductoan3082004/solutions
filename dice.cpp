#include<bits/stdc++.h>

using namespace std;

#define task "dice"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<ll,ll> pii;

const int mxn=1e5+5;
int a[mxn],n,k,trace[mxn];
ll dp[mxn];
void solve()
{
  cin>>n>>k;
  for(int i=1;i<=n;++i) {
    cin>>a[i];
  }
  ll ans=-1e15;
  priority_queue<pii,vector<pii>> q;
  q.push({0,0});
  for(int i=0;i<=n;++i) {
    while(!q.empty()&&q.top().se<i-k) q.pop();
    dp[i]=a[i]+q.top().fi;
    trace[i]=q.top().se;
    ans=max(ans,dp[i]);
    q.push({dp[i],i});
  }
  trace[0]=-1;
  cout<<ans<<endl;
  int j=0;
  for(int i=0;i<=n;++i)
    if(ans==dp[i]) j=i;
  vector<int>res;
  while(j!=-1) {
    res.push_back(j);
    j=trace[j];
  }
  reverse(res.begin(),res.end());
  cout<<res.size()<<' ';
  for(int i:res)cout<<i<<' ';
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}




