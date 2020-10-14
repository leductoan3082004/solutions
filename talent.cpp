#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "talent"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

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
typedef long long ll;
typedef pair<ll,ll> pii;

const ll mxn=100005;
ll n,m;
pii a[mxn];
ll wd[mxn],w[mxn];
void solve()
{
    read(n); read(m);
    for(ll i=1;i<=n;++i) read(a[i].fi);
    for(ll i=1;i<=n;++i) read(a[i].se);

    sort(a+1,a+n+1);

    for(ll i=1;i<=n;++i) {
        wd[i]=wd[i-1]+1LL*a[i].fi*a[i].se;
        w[i]=w[i-1]+a[i].se;
    }
    for(ll i=1;i<=m;++i) {
        ll p; read(p);
        ll l=1,r=n, k=n;
        while(l<=r) {

            ll mid=(l+r)>>1;
            if(a[mid].fi<p) {
                l=mid+1;
                k=mid;
            }
            else r=mid-1;
        }
        ll ans=0;
        ans+=1LL*p*w[k]-wd[k];
//        cout<<wd[n]-wd[k]<<endl;
        ans+=(wd[n]-wd[k])-(1LL*p*(w[n]-w[k]));
        write(ans); putchar('\n');
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





