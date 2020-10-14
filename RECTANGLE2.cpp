#include<bits/stdc++.h>

using namespace std;

#define task "RECTANGLE2"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    while (1) {
        int n = -1 , m = - 1 , p = - 1;
        cin >> n >> m >> p;
        if (n == -1 || m == -1 || p == -1) break;
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if ((i + j) * 2 >= p) {
                    ans += (n - i + 1) * (m - j + 1);
                }
            }
        }
        cout << ans << '\n';
    }
}










