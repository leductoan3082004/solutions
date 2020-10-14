#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "paliny"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;

const ll mod=998244353;
const int mxn=50005;
const int base=331;

string s;
int n;
ll pw[mxn],h1[mxn],h2[mxn];

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
    cin>>n;
    cin>>s;
    s=' '+s;
    pw[0]=1;
    for(int i=1;i<=n;++i) pw[i]=(pw[i-1]*base)%mod;

    for(int i=1;i<=n;++i)
        h1[i]=(h1[i-1]*base+s[i]-'a'+1)%mod;
    for(int i=n;i>=1;--i)
        h2[i]=(h2[i+1]*base+s[i]-'a'+1)%mod;

    int ans=0;
    for(int i=1;i<=n;++i) {
        int l=0,r=n;
        while(l<=r) {
            int mid=(l+r)>>1;
            if(i-mid<1||i+mid>n) r=mid-1;
            else if(get1(i-mid,i-1)==get2(i+1,i+mid)) {
                l=mid+1;
                ans=max(ans,mid*2+1);
            }
            else r=mid-1;
        }
        l=0, r=n;
        while(l<=r) {
            int mid=(l+r)>>1;
            if(i-mid+1<1||i+mid>n) r=mid-1;
            else if(get1(i-mid+1,i)==get2(i+1,i+mid)) {
                l=mid+1;
                ans=max(ans,2*mid);
            }
            else r=mid-1;
        }
    }
    cout<<ans;
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




