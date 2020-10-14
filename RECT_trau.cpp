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
#define task "RECT"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int N = 305;
int n , m , a[N][N],ans[N][N];
int main()
{
    TL
//    freopen(task".inp","r",stdin);
//    freopen(task".ans","w",stdout);

    Read(n); Read(m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            Read(a[i][j]);
            a[i][j] = 1 - a[i][j];
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int x = i; x <= n; ++x) {
                for (int y = j; y <= m; ++y) {
                    int area = a[x][y] - a[i - 1][y] - a[x][j - 1] + a[i - 1][j - 1];
                    if (area == (y - j + 1) * (x - i + 1)) {
                        ans[x - i + 1][y - j + 1] ++;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            Write(ans[i][j]);
            putchar(' ');
        }
        putchar('\n');
    }
}










