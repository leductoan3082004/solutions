#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "CYCLIC"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> ii;

const int mod=998244353;
const int mxn=100005;
const int base=311;

string s,t;
int n;
ll ha[mxn],hb[mxn],pw[mxn];

ll geta(int i, int j)
{
    return (ha[j]-ha[i-1]*pw[j-i+1]+mod*mod)%mod;
}
ll getb(int i, int j)
{
    return (hb[j]-hb[i-1]*pw[j-i+1]+mod*mod)%mod;
}
void solve()
{
    cin>>s;
    cin>>t;
    n=s.length();
    s=' '+s;
    t=' '+t;

    pw[0]=1;
    for(int i=1;i<=n;++i){
        ha[i]=(ha[i-1]*base+s[i]-'a'+1)%mod;
        hb[i]=(hb[i-1]*base+t[i]-'a'+1)%mod;
        pw[i]=pw[i-1]*base%mod;
    }
    int ans=(geta(1,n)==getb(1,n));
    for(int i=n;i>=2;--i){
        int ok=1;
        ok&=(geta(i,n)==getb(1,n-i+1));
        ok&=(geta(1,i-1)==getb(n-i+2,n));
        ans+=ok;
    }
    cout<<ans;
}
int main()
{
    TL
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    solve();
}
/// JUST KEEP TRAINING





