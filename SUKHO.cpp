#include<bits/stdc++.h>

using namespace std;

#define task "SUKHO"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef unsigned long long ll;

const ll N = 105;
ll dp[2][10005];
ll n , m , k , a[N];
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n >> m >> k;
    for (ll i = 1; i <= n; ++i) cin >> a[i];

    dp[0][0] = 1;

    for (ll i = 1; i <= n; ++i) {
        for (ll j = 0; j <= m; ++j) {
            dp[1][j] += dp[0][j];
            if (j - a[i] >= 0) dp[1][j] += dp[0][j - a[i]];
        }
        for (ll j = 0; j <= m; ++j) {
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
    }
    if (m == 0) dp[0][m] --;
    if (dp[0][m] >= k || dp[0][m] < 0) cout << "ENOUGH";
    else cout << dp[0][m];
}










