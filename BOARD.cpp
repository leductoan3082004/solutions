#include<bits/stdc++.h>

using namespace std;

#define task "BOARD"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const ll mod = 1e9 + 7;
ll n , m;

ll pw(ll n, ll k)
{
    if (k == 1) return n;
    if (k == 0) return 1;
    ll t = pw(n,k / 2);
    if (k & 1) return (((t * t) % mod) * n) % mod;
    else return (t * t) % mod;
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n >> m;
    cout << pw(2,1LL * (n - 1) * (m - 1));
}










