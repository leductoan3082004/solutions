#include<bits/stdc++.h>

using namespace std;

#define task "CNTPAIR"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ll ans = 0, n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> dd(3,0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        ans += dd[a[i] % 2];
        dd[a[i] % 2] ++;
    }
    cout << ans;
}











