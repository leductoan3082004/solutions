#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "VMQUABEO"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn = 1e6 + 5;
int n, l, d, a[mxn];
ll ans = 0;
void solve()
{
    cin >> n >> l >> d;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    deque<int> dmx,dmn;
    int j = 1;
    for (int i = 1; i <= n; ++i) {
        while (!dmx.empty() && a[dmx.back()] < a[i]) dmx.pop_front();
        while (!dmn.empty() && a[dmn.back()] > a[i]) dmn.pop_front();

        dmx.push_back(i);
        dmn.push_back(i);
        while (a[dmx.front()] - a[dmn.front()] > d) {
            if (dmx.front() == j) dmx.pop_front();
            if (dmn.front() == j) dmn.pop_front();
            ++j;
        }
        ans += max(0, i - j - d);

//        cout << j << ' ' << i << endl;
    }
    cout << ans;
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.











