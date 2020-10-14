#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "miller"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

int random(int l, int r)
{
    return l + rand() % (r - l + 1);
}
ll pw(int n, int k)
{
    if (k == 1) return n;
    if (k == 0) return 1;
    ll t = pw(n , k >> 1);
    if (k & 1) return t * t * n;
    else return t * t;
}
bool check(ll n)
{
    if (n == 2) return 1;
    if (n % 2 == 0 || n < 2) return 0;

    /// n - 1 = 2^0 * (n - 1)

    int k = random(1000,10000);
    for (int i = 1; i <= k; ++i) {
        int a = random(2,n - 2);
        int x =
    }
}
void solve()
{
    ll n; cin >> n;
    cout << (check(n) ? "prime" : "composite") << '\n';
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.










