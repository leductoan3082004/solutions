#include<bits/stdc++.h>

using namespace std;

#define task "DELGCD"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
int n,a[1000005];
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int k = a[1];
    for (int i = 2; i <= n; ++i) {
        k = __gcd(k,a[i]);
    }

    if (k > 1) cout << -1;
    else cout << 0;
}










