#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "V11WATER"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int oo = 2e9;
const ll inf = 1e15;
const int N = 2e5;

int a[N] , f[N] , g[N] , n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    a[0] = a[1];
    a[n + 1] = a[n];
    for (int i = 1; i <= n; ++i) f[i] = max(a[i], f[i - 1]);
    for (int i = n; i >= 1; --i) g[i] = max(a[i], g[i + 1]);

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int k = min(f[i] , g[i]);
        ans += k - a[i];
    }
    cout << ans ;
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.










