#include<bits/stdc++.h>

using namespace std;

#define task "acm"
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> ii;

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

const int mxn=8e5+5;
int n;
ii a[mxn],b[mxn];

void solve()
{
    read(n);
    for(int i=1;i<=2*n;++i) {
        read(a[i].fi); read(a[i].se);
        b[i].fi=a[i].fi-a[i].se;
        b[i].se=i;
    }
    sort(b+1,b+2*n+1);
    ll ans=0;
    for(int i=1;i<=n;++i) ans+=a[b[i].se].fi;
    for(int i=n+1;i<=2*n;++i) ans+=a[b[i].se].se;
    write(ans);
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






