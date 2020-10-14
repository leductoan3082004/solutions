#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "PBCWATER"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

struct three
{
    int x, y;
    int w;
};
struct cmp
{
    bool operator () (three a, three b)
    {
        return a.w > b.w;
    }
};

const int mxn = 1005;
int n, m, a[mxn][mxn], dp[mxn][mxn];
int d1[] = {0,0,-1,1};
int d2[] = {-1,1,0,0};
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    priority_queue<three,vector<three>, cmp > q;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = 2e9;
        }
    }

    for (int i = 1; i <= m; ++i) {
        dp[1][i] = a[1][i];
        dp[n][i] = a[n][i];
        q.push({1, i, a[1][i]});
        q.push({n, i, a[n][i]});
    }

    for (int i = 1; i <= n; ++i) {
        dp[i][1] = a[i][1];
        dp[i][m] = a[i][m];
        q.push({i, 1, a[i][1]});
        q.push({i, m, a[i][m]});
    }

    while (!q.empty()) {
        int x = q.top().x;
        int y = q.top().y;
        int len = q.top().w;
        q.pop();
        if (dp[x][y] < len) continue;

        for (int i = 0; i < 4; ++i) {
            int u = x + d1[i];
            int v = y + d2[i];
            if (!(u >= 1 && u <= n && v >= 1 && v <= m)) continue;
            int w = max(dp[x][y], a[u][v]);
            if (dp[u][v] > w) {
                dp[u][v] = w;
                q.push({u, v, w});
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ans += dp[i][j] - a[i][j];
        }
    }
    cout << ans << '\n';
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.











