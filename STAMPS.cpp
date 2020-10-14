#include<bits/stdc++.h>

using namespace std;

#define task "STAMPS"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;
const int N = 1e4 + 5;
int s,n,a[N],ans;
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> s >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= n; ++i) {
        if (s <= 0) break;
        s -= a[i];
        ans ++;
        if (s <= 0) break;
    }
    if (s > 0) ans = 0;
    cout << ans;
}










