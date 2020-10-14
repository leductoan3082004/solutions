#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "ptrang"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int oo = 2e9;
const ll inf = 1e15;
const int N = 6005;

int n , l , a[N], dp[N];
void solve()
{
    cin >> n >> l;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i <= n; ++i) dp[i] = 2e9;
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        for (int j = i; j >= 1; --j) {
            sum += a[j];
            if (sum > l) break;
            int k = l - sum;
            dp[i] = min(dp[i] ,max(k , dp[j - 1]));
        }
    }
//    for (int i = 1; i <= n; ++i) cout << dp[i] << ' ';
//    cout << endl;
    cout << dp[n];
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.









