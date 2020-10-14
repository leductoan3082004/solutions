#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "SKFIB"
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

const int N = 2505;
int dp[N][N], a[N], n;
void solve()
{
    Read(n);
    vector<pii> q;
    for (int i = 1; i <= n; ++i) {
        Read(a[i]);
        q.push_back({a[i],i});
    }
    sort(q.begin(),q.end());
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = 2;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {

            /// a[i] - a[j] , a[j], a[i]
            int k = lower_bound(q.begin(),q.end(),make_pair(a[i] - a[j],j)) - q.begin() -1 ;
            if (k >= 0 && k < q.size()) {
                k = q[k].second;
                if (a[k] == a[i] - a[j]) dp[i][j] = dp[j][k] + 1;
            }
            ans = max(ans,dp[i][j]);
        }
    }
    cout << ans << '\n';
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    int t;

    Read(t);
    while(t--) solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.











