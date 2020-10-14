#include<bits/stdc++.h>

using namespace std;

template <typename T>
inline void Read(T& x)
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
inline void Write(T x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}
#define task "SUBSEQUENCE"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const ll mod = 1e9 + 7;
ll a[500005];
ll f[500005];
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    ll n; Read(n);
    for (ll i = 1; i <= n; ++i) Read(a[i]);
    ll sum = 1;
    for (ll i = 1; i <= n; ++i) {
        ll cnt = (sum - f[a[i]] + mod * mod) % mod;
        f[a[i]] = (f[a[i]] + cnt) % mod;
        sum = (sum + cnt) % mod;
    }
    Write((sum - 1 + mod) % mod);
}









