#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "STMERGE"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int N = 1005;
const ll inf = 1e15;

int n , m , a[N][N];
ll dp[N][N][2];

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0 ; j <= m + 1; ++j) {
            for (int k = 0; k < 2; ++k) {
                dp[i][j][k] = inf;
            }
        }
    }

    dp[0][0][0] = dp[0][0][1] = 0;
    /// dp[i][j][0] chi phi chon i ki tu dau tien cua a
    /// va j ki tu cua b voi ket thuc o a

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0 && j == 0) continue;
            if (i - 1 >= 0) dp[i][j][0] = min(dp[i - 1][j][0] , dp[i - 1][j][1] + a[i][j]);
            if (j - 1 >= 0) dp[i][j][1] = min(dp[i][j - 1][1] , dp[i][j - 1][0] + a[i][j]);
        }
    }
    cout << min(dp[n][m][0] , dp[n][m][1]) << '\n';
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










