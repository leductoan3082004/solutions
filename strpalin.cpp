#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "strpalin"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;

const ll mod=998244353;
const int mxn=100005;
const int base=311;

string s;
int n;
ll h1[mxn],h2[mxn],pw[mxn];

ll get1(int i, int j)
{
    return (h1[j]-h1[i-1]*pw[j-i+1]+mod*mod)%mod;
}
ll get2(int i, int j)
{
    return (h2[i]-h2[j+1]*pw[j-i+1]+mod*mod)%mod;
}
void solve()
{
    cin>>s;
    s=' '+s;
    n=s.length()-1;
    pw[0]=1;
    for(int i=1;i<=n;++i) pw[i]=(pw[i-1]*base)%mod;
    for(int i=1;i<=n;++i)
        h1[i]=(h1[i-1]*base+s[i]-'a'+1)%mod;
    for(int i=n;i>=1;--i)
        h2[i]=(h2[i+1]*base+s[i]-'a'+1)%mod;

    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        if((r-l+1)%2==0)
        {
            int mid=(r+l)/2;
            if(get1(l,mid)==get2(mid+1,r)) cout<<1;
            else cout<<-1;
        }
        else
        {
            int mid=(l+r)/2;
            if(get1(l,mid-1)==get2(mid+1,r)) cout<<1;
            else cout<<-1;
        }
        cout<<'\n';
    }
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





