#include<bits/stdc++.h>

using namespace std;

#define task "pali2"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=2005;
const ll mod=998244353;
string s;
int n,dp[mxn][mxn],ans[mxn];
ll f[mxn],pw[mxn],g[mxn];
ll get1(int i, int j)
{
  return (f[j]-f[i-1]*pw[j-i+1]+mod*mod)%mod;
}
ll get2(int i, int j)
{
  return (g[i]-g[j+1]*pw[j-i+1]+mod*mod)% mod;
}
void solve()
{
  cin>>n;
  cin>>s;
  s=' '+s;
  pw[0]=1;
  for(int i=1;i<=n;++i) {
    pw[i]=(pw[i-1]*31)%mod;
  }
  for(int i=1;i<=n;++i) {
    f[i]=(f[i-1]*31+s[i]-'a'+1)%mod;
  }
  for(int i=n;i>=1;--i) {
    g[i]=(g[i+1]*31+s[i]-'a'+1)%mod;
  }
  for(int i=1;i<=n;++i) {
    ans[i]=2e9;
  }
  for(int i=1;i<=n;++i) {
    for(int j=i;j<=n;++j) {
      int mid=(i+j)>>1,ok=0;
      if((j-i+1)&1&&get1(i,mid)==get2(mid,j)) ok=1;
      if((j-i+1)%2==0&&get1(i,mid)==get2(mid+1,j)) ok=1;
      if(ok) {
        ans[j]=min(ans[j],ans[i-1]+1);
        dp[i][j]=1;
      }
    }
  }
  int j=n;
  cout<<ans[n]<<endl;
  vector<string> res;
  while(j>=1) {
    for(int i=j-1;i>=0;--i)
    if(dp[i+1][j]&&ans[i]+1==ans[j]) {
      string t="";
      for(int k=i+1;k<=j;++k) t+=s[k];
      res.push_back(t);
      j=i;
      break;
    }
  }
  reverse(res.begin(),res.end());
  for(int i=0;i<res.size();++i) cout<<res[i]<<endl;
}
int main()
{
  TL
  freopen(task".inp","r",stdin);
  freopen(task".out","w",stdout);
  solve();
}




