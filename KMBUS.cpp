#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "KMBUS"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    int n , l;
    cin >> n >> l;
    vector<ll> a(n + 1 , 0),f(l + 1 , 1e15);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    f[0] = 0;
    for (int i = 1; i <= l; ++i) {
        for (int j = 1; j <= min(i,n); ++j) f[i] = min(f[i],f[i - j] + a[j]);
    }

    cout << f[l];
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.










