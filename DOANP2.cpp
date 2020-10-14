#include<bits/stdc++.h>

using namespace std;

#define task "DOANP2"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

const int N = 1e5 + 5;
int n;
pair<int,int> a[N];
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1);
    int L = -1, R = -1 ;
    ll ans = 0;

    for (int i = 1; i <= n; ++i) {
        /// nằm bao nhau
        if (L <= a[i].first && a[i].second <= R) continue;
        /// nằm ngoài nhau
        if (R < a[i].first) {
            ans += a[i].second - a[i].first;
            L = a[i].first;
            R = a[i].second;
            continue;
        }
        /// giao (tiếp xúc ) nhau
        if (a[i].first <= R && a[i].second > R) {
            ans += a[i].second - R;
            R = a[i].second;
            continue;
        }
    }
    cout << ans;
}










