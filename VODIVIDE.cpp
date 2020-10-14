#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "VODIVIDE"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int oo = 2e9;
const ll inf = 1e15;
const int N = 5005;

int a[N] , b[N] , dp[N][N] , n , m;
void solve()
{
    cin >> n ;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    dp[0][0] = 0;
    /// dp[i][j] trong i dong xu
    /// Son so huu j dong xu
    /// dp[i + 1][j + 1] = dp[i][j] + b[j + 1]
    /// dp[i + 1][j] = dp[i][j];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j + 1 <= i - j + 1) dp[i + 1][j + 1] = dp[i][j] + b[j + 1];
            dp[i + 1][j] = max(dp[i + 1][j] , dp[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cout << dp[i][j] << ' ';
        cout << endl;
    }
    cout << dp[n][n / 2];
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.










