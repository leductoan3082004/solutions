#include<bits/stdc++.h>

using namespace std;

#define task "polygon_area"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;
int n;
pair<int,int> a[1000];
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second ;
    }
    double ans = 0;
    a[n + 1] = a[1];
    for (int i = 1; i <= n; ++i) {
        ans += (a[i].first - a[i + 1].first) * (a[i].second + a[i + 1].second);
    }
    cout << fixed << setprecision(2) << ans / 2.00;
}










