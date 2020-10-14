#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "C11BC1"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int oo = 2e9;
const ll inf = 1e15;
const int N = 1e5 + 5;
const int mod = 790972;

int dp[2][55], n, k;
pii a[N];
int cal(int L, int R)
{
    for (int i = 0; i <= k; ++i) {
        dp[1][i] = 0;
        dp[0][i] = 0;
    }
    dp[0][0] = 1;
    for (int i = L; i <= R; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[1][j] = (dp[0][j - 1] * a[i].first) % mod;
            dp[1][j] = (dp[1][j] + dp[0][j]) % mod;
        }
        for (int j = 1; j <= k; ++j) {
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
    }
    return dp[0][k];
}
bool cmp(pii a, pii b)
{
    return a.second < b.second;
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1, cmp);
    ll ans = cal(1,n);
    int L = 1, R = 1;
    while (L <= n && R <= n) {
        while (a[R + 1].second ==  a[L].second) ++R;
//        cout << L << ' ' << R << ' ' << cal(L,R) << endl;
        ans = (ans - cal(L,R) + mod) % mod;
        L = R + 1;
    }
    cout << ans;
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.










