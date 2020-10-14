#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "NKCABLE"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int N = 25005;
ll dp[3][N];
int n , a[N];
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n;
    for (int i = 1; i < n; ++i) cin >> a[i];
    dp[1][2] = a[1];
    dp[0][2] = 2e9;
    /// dp[1][i] i ~ (i - 1)
    /// dp[0][i] (i - 1)   (i)
    for (int i = 3; i <= n; ++i) {
        dp[0][i] = dp[1][i - 1];
        dp[1][i] = min(dp[0][i - 1] , dp[1][i - 1]) + a[i - 1];
    }
    cout << dp[1][n];
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.










