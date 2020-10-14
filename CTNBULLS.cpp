#include<bits/stdc++.h>

using namespace std;

#define task "CTNBULLS"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    int n ,k;
    cin >> n >> k;
    vector<int> f(n + 1, 0);
    for (int i = 1; i <= k + 1; ++i) f[i] = i + 1;
    for (int i = k + 2; i <= n; ++i) {
        f[i] = (f[i - 1] + f[i - k -1 ]) % 2111992;
    }
    cout << f[n];
}










