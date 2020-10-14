#include<bits/stdc++.h>

using namespace std;

#define task "MINCUT"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

const int N = 1005;
int a[N][N] , n, m , k;
ll f[N][N];
ll get(int x, int y, int u, int v )
{
    return f[u][v] - f[x - 1][v] - f[u][y - 1] + f[x - 1][y - 1];
}

ll doc(int x, int y, int u, int v)
{
    int l = y , r = v;
    ll all = get(x,y,u,v);
    int ans = y;
    while (l <= r) {
        int mid = (l+r)/2;
        if (get(x,y,u,mid) <= all / 2) {
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    ll res = abs(all - 2 * get(x,y,u,ans));
    if (ans - 1 >= y ) res = min(res,abs(all - 2 * get(x,y,u,ans - 1)));
    if (ans + 1 <= v) res = min(res,abs(all - 2 * get(x,y,u,ans + 1)));
    return res;
}
ll ngang(int x, int y, int u, int v)
{
    int l = x, r = u, ans = x;
    ll all = get(x,y,u,v) ;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (get(x,y,mid,v) <= all / 2) {
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    ll res = abs(all - 2 * get(x,y,ans,v));
    if (ans - 1 >= x ) res = min(res,abs(all - 2 * get(x,y,ans - 1,v)));
    if (ans + 1 <= u) res = min(res,abs(all - 2 * get(x,y,ans + 1,v)));
    return res;
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)  {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
        }
    }
    while ( k -- ) {
        int x , y , u ,v;
        cin >> x >> y >> u >> v;
        ll ans = ngang(x,y,u,v);
        ans = min(ans,doc(x,y,u,v));
        cout << ans << '\n';
    }
}










