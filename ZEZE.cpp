#include<bits/stdc++.h>

using namespace std;

#define task "zeze"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    int n;
    cin >> n;
    int d2 = 0, d5 = 0;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        while (x % 5 == 0 && x > 0) {
            d5 ++;
            x /= 5;
        }
        while (x % 2 == 0 && x > 0) {
            x /= 2;
            d2 ++;
        }
    }
    cout << min(d2,d5);
}









