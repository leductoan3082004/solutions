#include<bits/stdc++.h>
using namespace std;

#define task "SUPERDROMIC"
#define fi first
#define se second
#define fore(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define ford(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)

typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int base=331;
const int mod=1e9+3;
const int mxn=1e5+5;

string s;
ll pw[mxn],h[mxn];

ll get(int i, int j)
{
    return (h[j]-h[i-1]*pw[j-i+1]+(ll)mod*mod)%mod;
}
void solve()
{
    cin>>s;
    s=' '+s;
    int n=s.size()-1;
    for(int i=1;i<=n;++i)
    {
        pw[i]=pw[i-1]*base%mod;
        h[i]=(h[i-1]*base+s[i]-'a'+1)%mod;
    }
    int len1=0, len2=0;
    for(int i=1;i<=(n+1)/2;++i)
    {
        if(2*i<=n&&get(1,i)==get(i+1,2*i)) len1=max(len1,2*i);
        if(2*i-1<=n&&get(1,i-1)==get(i+1,2*i-1)) len1=max(len1,(i-1)*2+1);
    }
    for(int i=1;i<=(n+1)/2;++i)
    {
        if(2*i<=n&&get(1,i)==get(i+1,2*i)) len1=max(len1,2*i);
        if(2*i-1<=n&&get(1,i-1)==get(i+1,2*i-1)) len1=max(len1,(i-1)*2+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    solve();
}


