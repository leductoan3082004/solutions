#include<bits/stdc++.h>

using namespace std;

#define task "led"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<ll,ll> pii;

void solve1()
{
  string s;
  cin>>s;
  ll ans=0;
  vector<ll> cost={6,2,5,5,4,5,6,3,7,6};
  for(ll i=0;i<s.length();++i) {
    ll c=s[i]-'0';
    ans+=cost[c];
  }
  cout<<ans;
}
void solve2()
{
  string s;
  cin>>s;
  vector<ll> upp={1,5,1,2,2,3,1,2,0,0};
  vector<ll> lww={0,1,0,0,0,0,0,2,0,1};
  reverse(s.begin(),s.end());
  ll ans=0;
  for(ll i=0;i<s.length();++i) {
    ll tmp=1;
    ll ci=s[i]-'0';
    for(ll j=0;j<i;++j) {
      ll cj=s[j]-'0';
      tmp*=upp[cj]+lww[cj]+1;
    }
//    cout<<upp[ci]<<' '<<tmp<<endl;
    ans+=upp[ci]*tmp;
//    cout<<ans<<endl;
  }
  cout<<ans;
}
void solve()
{
  ll v;cin>>v;
  --v;
  if(!v) solve1();
  else solve2();
}
int main()
{
  TL
//  freopen(task".inp","r",stdin);
//  freopen(task".out","w",stdout);
  solve();
}






