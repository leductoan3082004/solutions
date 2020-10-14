#include<bits/stdc++.h>

using namespace std;

#define task "GTHH"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

const int N = 1e5 + 5;
int n , a[N];
ll dp[N][2];
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = max(dp[i - 1][0] , dp[i - 1][1] + abs(1 - a[i - 1]));
        dp[i][1] = max(dp[i - 1][1] + abs(a[i] - a[i - 1]), dp[i - 1][0] + abs(a[i] - 1));
    }
    cout << max(dp[n][0], dp[n][1]) ;
}










