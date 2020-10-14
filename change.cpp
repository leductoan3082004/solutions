#include<bits/stdc++.h>

using namespace std;

#define task "CHANGE"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mx = 3e5 + 5;
int s , n, a[mx];
map<int,int> dp;
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> s >> n;

    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = -4 * s; i <= 4 * s; ++i) dp[i] = 2e9;
    dp[0] = 0;
    for (int j = -4 * s; j <= 4 * s; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (j - a[i] >= -mx) dp[j] = min(dp[j], dp[j - a[i]] + 1);
            if (j + a[i] <= mx) dp[j] = min(dp[j] ,dp[j + a[i]] + 1);
        }
    }
    cout << dp[s];
}










