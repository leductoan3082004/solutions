#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "VBOARD"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int oo = 2e9;
const ll inf = 1e15;
const int N = 506;

int a[N][N] , dp[N][N][2], n;

int get(int k, int a, int b, int x, int y)
{
    return dp[x][y][k] - dp[x][b - 1][k] - dp[a - 1][y][k] + dp[a - 1][b - 1][k];
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    int m = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j][0] = dp[i - 1][j][0] + dp[i][j - 1][0] - dp[i - 1][j - 1][0];
            dp[i][j][1] = dp[i - 1][j][1] + dp[i][j - 1][1] - dp[i - 1][j - 1][1];
            if (j % 2 == m) dp[i][j][0] += a[i][j];
            else dp[i][j][1] += a[i][j];
        }
        m = 1 - m;
    }
//    cout << get(1,5,2,5,5) << endl;
    int q; cin >> q;
    while (q--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        int ans1 = get(0,a,b,x,y);
        int ans2 = get(1,a,b,x,y);
        cout << abs(ans1 - ans2) << '\n';
    }
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.










