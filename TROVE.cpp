#include<bits/stdc++.h>

using namespace std;

#define task "TROVE"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef unsigned long long ll;
const int mod = 1e9 + 7;
const int N = 3e5 + 5;
ll gt[N];
void giaithua()
{
    gt[1] = 1;
    for (ll i = 2; i <= 3e5; ++i) {
        gt[i] = (1LL * gt[i - 1] * i) % mod;
    }
}
ll Pow(ll n, ll k)
{
    if (k == 1) return n;
    if (k == 0) return 1;
    ll t = Pow(n , k / 2);
    if (k % 2 == 1) return (((t * t) % mod) * n) % mod;
    else return ( t * t ) % mod;
}
ll MOD(ll n)
{
    return Pow(n,mod - 2);
}
ll catalan(int n)
{
    ll m = (gt[n] * gt[n + 1]) % mod;
    ll ans = (gt[2 * n] * MOD(m)) % mod;
    return ans;
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    int n;
    cin >> n;
    giaithua();
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0) {
            ans = (ans + catalan(i / 2)) % mod;
        }
    }

    cout << ans;
}










