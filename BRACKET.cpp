#include<bits/stdc++.h>

using namespace std;

#define task "BRACKET"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

const ll mod = 1e9 + 7;
const ll N = 2e6 + 5;
ll fact[N] , ans = 1;
ll n , m , a[N] , s[N] , top;
ll pw(ll val, ll k)
{
    if (k == 1) return val;
    if (k == 0) return 1;
    ll t = pw(val , k / 2);
    if (k & 1) return (((t * t) % mod)* val) % mod;
    else return (t * t) % mod;
}
ll inversion(ll M)
{
    return pw(M , mod - 2);
}
ll cal(ll num)
{
    if (num == 0) return 1;
    ll M = (1LL * fact[num] * fact[num + 1]) % mod;
    ll ans = (1LL * inversion(M) * fact[2 * num]) % mod;
    return ans;
}
void mul(ll &a, ll b)
{
    a = (a * b) % mod;
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n >> m;
    if (n & 1) return cout << 0 , 0 ;

    fact[0] = 1;
    for (ll i = 1; i <= 4 * n; ++i) {
        fact[i] = (1LL * fact[i - 1] * i) % mod;
    }
    for (ll i = 1; i <= m; ++i) {
        ll u , v;
        cin >> u >> v;
        a[u] = i;
        a[v] = -i;
    }
    int dem = 0;
    for (ll i = 1; i <= n; ++i) {
        if (a[i] > 0) {
            if (top) {
                int dis = i - s[top] - 1;
                if (dis & 1) return cout << 0 , 0 ;

            }
            s[++top] = i;

        }
        else if (a[i] < 0) {
            if (-a[i] == a[s[top]]) {
                int dis = i - s[top] - 1;
                if (dis & 1) return cout << 0 , 0 ;
                mul(ans,cal(dis / 2));
                --top;
            }
            else {
                return cout << 0 << endl ,0;
            }
        }
        else {
            dem ++ ;
            if (a[i + 1] > 0 && !top) {
                mul(ans,(dem + 1) / 2);
            }
            dem = 0;
        }
    }
    mul(ans,cal(dem / 2));
    cout << ans;
}










