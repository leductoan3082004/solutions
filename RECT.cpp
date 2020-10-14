#include<bits/stdc++.h>

using namespace std;

#define task "RECT"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int N = 305;

int a[N][N],q[N][N],ans[N][N],n,m;
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cin >> a[i][j];
    }
    for (int i = 1; i <= n; ++i) q[i][m + 1] = m + 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 1; --j) {
            if (a[i][j]) q[i][j] = j;
            else q[i][j] = q[i][j + 1];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int c = m + 2;
            for (int k = i; k <= n; ++k) {
                c = min(c , q[k][j] - 1);
                if (c < j) break;
                ++ans[k - i + 1][c - j + 1];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 1; --j) ans[i][j] += ans[i][j + 1];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cout << ans[i][j] << ' ';
        cout << '\n';
    }
}










