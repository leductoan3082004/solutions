#include<bits/stdc++.h>

using namespace std;

#define task "NKLEAVES"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

const int N = 100005;
int dp[N][20],a[N],n,k;
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    /// them a[i] vao dong j dp[i][j] = dp[i + 1][j] * 2 + a[i];
    /// them a[i] vao dong moi j : dp[i][j + 1] = dp[i + 1][j]
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) dp[i][j] = -2e9;
    }
    dp[n + 1][0] = 0;
    for (int i = n; i >= 1; --i){
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = max(dp[i + 1][j] * 2 + a[i],dp[i][j]);
            dp[i][j + 1] = max(dp[i][j + 1],dp[i + 1][j]);
        }
    }
    cout << dp[n][k] ;
}










