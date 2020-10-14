#include<bits/stdc++.h>

using namespace std;

#define task "SEQK"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<ll,ll> pii;

const ll mod = 10000000007;
const ll N = 5005;
ll k , m ,n, dp[N][N];
void add(ll &a, ll b)
{
    a = (a + b) % mod;
}
int main()
{
    TL
//    freopen(task".inp","r",stdin);
//    freopen(task".out","w",stdout);

    cin >> k >> m >> n;

    for (ll i = 1; i < m; ++i) dp[1][i] = 1;

    for (ll i = 2; i <= n; ++i) {
        for (ll j = 1; j < m; ++j) {
            if (j - k > 0) add(dp[i][j] ,  dp[i - 1][j - k]);
            if (j + k < m) add(dp[i][j] , dp[i - 1][j + k]);
        }
    }

    ll ans = 0;
    for (ll i = 1; i < m; ++i) add(ans,dp[n][i]);
    cout << ans;
}










