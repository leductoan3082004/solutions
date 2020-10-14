#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "COWGIRL"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int oo = 2e9;
const ll inf = 1e15;
const int N = 40;

int n , m;
ll dp[40][(1 << 8)];
int BIT(int n, int i)
{
    return (n >> i) & 1;
}
bool valid(int mask , int pre_mask)
{
    for (int j = 1; j < m; ++j) {
        int ok = 1;
        if (BIT(mask,j) && BIT(pre_mask,j)
            && BIT(mask, j - 1) && BIT(pre_mask,j - 1)) return 0;
        if (!BIT(mask,j) && !BIT(pre_mask,j)
            && !BIT(mask, j - 1) && !BIT(pre_mask,j - 1)) return 0;
    }
    return 1;
}
void solve()
{
    cin >> n >> m;
    if (n < m) swap(n, m);
    for (int i = 0; i < n; ++i) {
        for (int mask = 0; mask < (1 << m); ++mask) {
            dp[i][mask] = 0;
        }
    }
    for (int mask = 0; mask < (1 << m); ++mask) dp[0][mask] = 1;
    for (int i = 1; i < n; ++i) {
        for (int mask = 0; mask < (1 << m); ++mask) {
            for (int pre_mask = 0; pre_mask < (1 << m); ++pre_mask) {
                if (valid(mask,pre_mask)) dp[i][mask] += dp[i - 1][pre_mask];
            }
        }
    }
    ll ans = 0;
    for (int mask = 0; mask < (1 << m); ++mask) ans += dp[n - 1][mask];
    cout << ans << '\n';
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    int t; cin >> t;
    while (t--) solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.










