#include<bits/stdc++.h>

using namespace std;

#define task "COIN"
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

const int N = 1e6 + 5;
int n , k;
pair<ll,int> a[N];
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    Read(n); Read(k);
    /// O ngua , R sap
    /// O = k . R
    for (int i = 1; i <= n; ++i) {
        char c ; c = getchar();
        a[i].first = (c == 'O' ? (-1) : k);
        a[i].first += a[i - 1].first;
        a[i].second = i;
    }

    a[0] = {0,0};
    sort(a,a + n + 1);
    int i = 0 , ans = 0;
    while (i <= n) {
        int j = i;
        while (a[j].first == a[j + 1].first) ++j;
        ans = max(ans , a[j].second - a[i].second);
        i = j + 1;
    }
    Write(ans);
}










