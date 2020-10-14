#include<bits/stdc++.h>

using namespace std;

#define task "TFIELD"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

const ll  N = 1005;
pair<ll,ll> a[N],f[N];
ll  n,k;
int  main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n >> k;
    for (ll  i = 1; i <= n; ++i) {
        ll  d, t;
        cin >> d >> t;
        for (ll  j = 1; j <= d; ++j) {
            cin >> a[j].first >> a[j].second;
        }
        ll sum = 0;
        a[d + 1] = a[1];
        for (ll  j = 1; j <= d; ++j) {
            sum += (a[j].first - a[j + 1].first) * (a[j].second + a[j + 1].second);
        }

        f[i] = make_pair(sum,t);
    }

    sort(f + 1, f + n + 1, greater<pair<ll ,ll > >() );
    f[n + 1] = {0,0};
    for (ll  i = 1; i <= n; ++i) {
        f[i].first -= f[i + 1].first;
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        vector<pair<ll,ll> > dp(n + 1,{0,0});
        dp[0] = {0, -1};
        for (int j = 1; j <= n; ++j) {
            dp[j].first += dp[j - 1].first + f[j].first;
            dp[j].second = dp[j - 1].second + (f[j].second != f[i].second);

        }

        int l = 1;
        for (int r = 1; r <= n; ++r) {
            while (l <= r && dp[r].second - dp[l - 1].second > k) l ++;
            ans = max(ans,dp[r].first - dp[l - 1].first);
        }
    }
    if (ans % 2 == 1) cout << ans/2 << ".5";
    else cout << ans /  2 << ".0";
}










