#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "BCDIV"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int oo = 2e9;
const ll inf = 1e15;
const int N = 2e5;

int n , k;
ll dp[30][30];
void solve()
{
    cin >> n >> k;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][j] += dp[i - 1][j] * j;
            dp[i][j] += dp[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j)  {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    cout << dp[n][k] << '\n';
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










