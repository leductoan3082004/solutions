#include<bits/stdc++.h>
using namespace std;
#define task "vostr"
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int base=331;
const int mod=1e9+9;
const int N=1000005;

int n,m;
string s,t;
ll hs[N],ht[N],pw[N];

ll get(ll h[], int i, int j)
{
    return (h[j]-h[i-1]*pw[j-i+1]+1LL*mod*mod)%mod;
}
void solve()
{
    cin>>n>>m;
    cin>>s>>t;
    s=' '+s;
    t=' '+t;
    for(int i=1;i<=n;++i)
    {
        hs[i]=(hs[i-1]*base+s[i]-'a'+1)%mod;
    }
    for(int i=1;i<=m;++i)
    {
        ht[i]=(ht[i-1]*base+t[i]-'a'+1)%mod;
    }
    pw[0]=1;
    for(int i=1;i<=max(n,m);++i)
    {
        pw[i]=pw[i-1]*base%mod;
    }
    int q;
    cin>>q;
//    cout<<get(hs,1,3)<<' '<<get(ht,1,3)<<'\n';
    for(int iii=1;iii<=q;++iii)
    {
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        int len1=r1-l1+1, len2=r2-l2+1;
        if(len1==len2&&get(hs,l1,r1)==get(ht,l2,r2)) {cout<<"="; continue;}
        int l=1, r=min(len1,len2)-1;
        int len=0;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(get(hs,l1,l1+mid-1)==get(ht,l2,l2+mid-1))
            {
                l=mid+1;
                len=mid;
            }
            else r=mid-1;
        }
        if(len1<len2&&s[l1+len]==t[l2+len]) cout<<"<";
        else if(s[l1+len]<t[l2+len]) cout<<"<";
        else cout<<">";
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



