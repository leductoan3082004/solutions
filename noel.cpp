#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "noel"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<ll,ll> pii;

const ll mxn=1000005;
ll len,f[mxn][30];
string s;
ll n;

ll cal_pos(ll line)
{
   ll a=line, b=line+1;
   if(a&1) {
      a%=len;
      b=(b/2)%len;
   }
   else {
      a=(a/2)%len;
      b%=len;
   }
   return (a*b)%len;
}
void solve()
{
   cin>>n;
   cin>>s;
   s=' '+s;
   len=s.length()-1;
   for(ll i=1;i<=len;++i) {
      ll c=s[i]-'A';
      for(ll j=0;j<26;++j) {
         f[i][j]=f[i-1][j]+(c==j);
      }
   }
   ll t;
   cin>>t;
   while(t--) {
      ll l; char ch;
      cin>>l>>ch;
      ll c=ch-'A';
      ll p=cal_pos(l-1);
      ++p;
      if(p+l-1<=len) {
         cout<<f[p+l-1][c]-f[p-1][c]<<'\n';
         continue;
      }
      ll ans=f[len][c]-f[p-1][c];
      ll remain=l-(len-p+1);
      ans+=remain/len*f[len][c];
      remain%=len;
      ans+=f[remain][c];
      cout<<ans<<'\n';
   }
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




