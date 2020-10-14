#include<bits/stdc++.h>

using namespace std;

#define task "BRIDGES"

typedef pair<ll ,ll > ii;
typedef long long ll;

int  main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    ll  n;
    cin >> n;
    vector<ll > a(n), odd(n + 1), even(n+1), L(n+1), R(n+1), Odd(n+5);
    for (ll  i = 1; i < n; ++i) {
        cin >> a[i];
        if (a[i] & 1) {
            odd[i] = a[i];
            even[i] = a[i] - 1;
        }
        else {
            odd[i] = a[i] - 1;
            even[i] = a[i];
        }
        Odd[i] = Odd[i - 1] + odd[i];
    }

    for (ll  i = n - 1; i >= 0; i--) {
        if (a[i] <= 1) R[i] = 0;
        else R[i] = R[i + 1] + even[i + 1];
    }
    for (ll  i = 1; i <= n; ++i) {
        if (a[i] <= 1) L[i] = 0;
        else L[i] = L[i - 1] + even[i];
    }
    ll ans = 0, cur = 0;
    for (ll  i = 1; i < n; ++i) {
        cur  = max(cur,1LL * (L[i] - Odd[i]));
        ans = max(ans, R[i] + Odd[i] + cur);
    }
    cout << ans;
}






