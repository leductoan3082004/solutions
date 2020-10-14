#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "V8SCORE"
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

const int N = 25;
const int S = 205;
int a[N][N] , s, k , n, ans[N], f[N];
void print()
{
    cout << "YES\n";
    for (int i = 1; i <= k; ++i) cout << ans[i] << ' ';
}
void cal(int j)
{
    if (j == k + 1 && f[k] == s) {
        print();
        exit(0);
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i][j] >= ans[j - 1] && f[j - 1] + a[i][j] * (k - j + 1) <= s) {
            ans[j] = a[i][j];
            f[j] = f[j - 1] + a[i][j];
            if (j <= k) cal(j + 1);
        }
    }
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    /// giam khao : n
    /// bai thi : k
    Read(s); Read(k); Read(n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            Read(a[i][j]);
        }
    }
    cal(1);
    cout << "NO\n";
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.










