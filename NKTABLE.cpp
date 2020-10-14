#include<bits/stdc++.h>

using namespace std;

#define task "NKTABLE"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;
const int N = 505;
string dp[N][N];
char a[N][N];
int n,m;
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cin >> a[i][j];
    }
    for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= m; ++j) dp[i][j] = "3";
    dp[1][0] = "";
    dp[0][1] = "";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == '2') continue;
            if (dp[i - 1][j] == "3" && dp[i][j - 1] == "3") continue;
            if (dp[i - 1][j] == "3") dp[i][j] = dp[i][j - 1] + a[i][j];
            else if (dp[i][j - 1] == "3") dp[i][j] = dp[i - 1][j] + a[i][j];
            else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]) + a[i][j];
        }
    }
    cout << dp[n][m];
}










