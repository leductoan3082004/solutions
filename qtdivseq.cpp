#include<bits/stdc++.h>
using namespace std;
#define task "qtdivseq"
#define lb lower_bound
#define ub upper_bound
#define alll(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; ++i)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; --i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> pii;
template <typename T>
inline void read(T& x)
{
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' | c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}
const ll mod=1e9+7;
ll n,a[1000005],dp[1000005];

ll pw(ll n, ll k)
{
    if(k==1) return n;
    if(k==0) return 1;
    ll t=pw(n,k/2);
    if(k&1) return t*t%mod*n%mod;
    else return t*t%mod;
}
ll C(ll n, ll k)
{
    ll tu=1, mau=1;
    for(ll i=1;i<=n;++i) tu=(ll)tu*i%mod;
    for(ll i=1;i<=k;++i) mau=(ll)mau*i%mod;
    for(ll i=1;i<=(n-k);++i) mau=(ll)mau*i%mod;
    return (ll)tu*pw(mau,mod-2)%mod;
}
void solved()
{
    ll k;
    read(n); read(k);
    ll sum=0;
    for(ll i=1;i<=n;++i) read(a[i]),sum+=a[i];
//    cout<<sum<<endl;
    if(sum==0)
    {
        ll s=0;
        ll cnt=0;
        for(ll i=1;i<=n;++i)
        {
            s+=a[i];
            if(s==0) ++cnt;
        }
        if(cnt<k) cout<<0;
        else
        cout<<C(cnt-1,k-1);
        return;
    }
    if(sum%k!=0)
    {
        cout<<0;
        return;
    }
    if(k==n)
    {
        ll ok=1;
        for(ll i=1;i<n;++i) ok&=a[i]==a[i+1];
        cout<<ok;
        return;
    }
    dp[0]=1;
    ll s=0, seq=sum/k;
    for(ll i=1;i<=n;++i)
    {
        s+=a[i];
        ll ck=0;
        if(s%seq==0) ck=s/seq;
        else continue;
        if(ck<=0) continue;
        dp[ck]=(ll)(dp[ck-1]+dp[ck])%mod;
    }
    cout<<dp[k];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    solved();
}
