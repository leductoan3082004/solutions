#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "SEGEMENTS"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
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
typedef long long ll;
typedef pair<int,int> pii;

const int oo = 2e9;
const ll inf = 1e15;
const int N = 1e6 + 5;

int a[N] , n, ans =0 ;
ll sum = 0;

void check(int uoc)
{
    ll s = 0;
    int d = 0;
    for (int i = 1; i <= n; ++i) {
        s += a[i];
        if (s == uoc) {
            ++d;
            s = 0;
        }
        else if (s > uoc) return;
    }
    ans = max(ans,d);
//    exit(0);
}
void solve()
{
    Read(n);
    for (int i = 1; i <= n; ++i) {
        Read(a[i]);
        sum += a[i];
    }

    for (ll i = 1; i * i <= sum; ++i) {
        if (sum % i == 0) {
            check(i);
            check(sum / i);
        }
    }
    cout << ans ;
}
int main()
{
    TL
//    freopen(task".inp","r",stdin);
//    freopen(task".out","w",stdout);
    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.










