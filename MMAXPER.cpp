#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "MMAXPER"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int N = 1005;
pii a[N];
int n , dp[N][2];
int main()
{
    TL
//    freopen(task".inp","r",stdin);
//    freopen(task".out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
        assert(a[i].first < a[i].second);
    }
    /// dp[i][0] dat ngang
    /// dp[i][1]  dat doc
    dp[1][0] = a[1].second;
    dp[1][1] = a[1].first;
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = max(dp[i - 1][0] + abs(a[i].first - a[i - 1].first) + a[i].second,
                       dp[i - 1][1] + abs(a[i].first - a[i - 1].second) + a[i].second);
        dp[i][1] = max(dp[i - 1][0] + abs(a[i].second - a[i - 1].first) + a[i].first,
                       dp[i - 1][1] + abs(a[i].second - a[i - 1].second) + a[i].first);
    }
    cout << max(dp[n][1], dp[n][0]);
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.










