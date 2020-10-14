#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "exercise"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int oo = 2e9;
const ll inf = 1e15;
const int N = 25;
const int B = (1 << 20) + 5;

int n , m , a[N][N];
ll dp[N][B];

int BIT(int n, int i)
{
    return (n >> i) & 1;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u , v;
        cin >> u >> v;
        --u ; -- v;
        a[u][v] = 1;
    }
    for (int i = 0; i < n; ++i) dp[i][1 << i] = 1;
    for (int i = 0; i < n; ++i) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (BIT(mask, i)) {
                int pre_mask = mask & (~(1 << i));
                for (int j = 0; j < n; ++j) {
                    if (BIT(pre_mask, j) && a[j][i]) {
                        dp[i][mask] += dp[j][pre_mask];
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            cout << dp[i][mask] << ' ';
        }
        cout << endl;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) ans += dp[i][(1 << n) - 1];
    cout << ans;
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.










