#include<bits/stdc++.h>

using namespace std;
/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "MILK"
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
typedef pair<ll,ll> pii;

const ll oo = 2e9;
const ll inf = 1e15;
const ll N = 2e6 + 5;
const ll mx = 1e7 + 5;

pii a[N];
int ans = 0, n, m, k;
void solve()
{
    Read(n); Read(m); Read(k);
    for (int i = 1; i <= n; ++i) {
        Read(a[i].first);
        a[i].second = 1;
    }
    for (int i = n + 1; i <= n + m; ++i) {
        Read(a[i].first);
        a[i].second = 2;
    }
    sort(a + 1, a + n + m + 1);
    int day = 0, cnt = 0;
//    for (int i =1 ; i <= n + m; ++i) cout << a[i].first << ' ' << a[i].second << endl;
    for (int i = 1; i <= n + m; ++i) {
        if (a[i].first < day) {
            if (a[i].second == 1) {
                cout << -1;
                return;
            }
            continue;
        }
        ++cnt;
        if (a[i].second == 2) ++ans;
        if (cnt == k) cnt = 0, ++day;
    }
    cout << ans;
}
int main()
{
    TL
//    freopen(task".inp","r",stdin);
//    freopen(task".out","w",stdout);

    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.










