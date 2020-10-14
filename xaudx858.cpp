#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "xaudx858"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;

const int mod=998244353;
const int mxn=100005;
const int base=311;

int n;
string s;
ll h1[mxn],h2[mxn],pw[mxn];

ll get1(int i, int j)
{
    return (h1[j]-h1[i-1]*pw[j-i+1]+1LL*mod*mod)%mod;
}
ll get2(int i, int j)
{
    return (h2[i]-h2[j+1]*pw[j-i+1]+1LL*mod*mod)%mod;
}
void solve()
{
    cin>>s;
    n=s.length();
    s=' '+s;

    pw[0]=1;
    for(int i=1;i<=n;++i) pw[i]=(pw[i-1]*base)%mod;

    for(int i=1;i<=n;++i)
        h1[i]=(h1[i-1]*base+s[i]-'a'+1)%mod;
    for(int i=n;i>=1;--i)
        h2[i]=(h2[i+1]*base+s[i]-'a'+1)%mod;
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        if(get1(i,n)==get2(i,n))
        {
            ans=i;
            break;
        }
    }
    for(int i=1;i<=n;++i) cout<<s[i];
    for(int i=ans-1;i>=1;--i) cout<<s[i];
}
int main()
{
    TL
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    solve();
}
/// JUST KEEP TRAINING





