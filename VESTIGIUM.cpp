#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "VESTIGIUM"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

int a[105][105];
void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    int row = 0, col = 0;
    for (int i = 1; i <= n; ++i) {
        vector<int> dd(n + 1 , 0);
        for (int j = 1; j <= n; ++j) {
            if (dd[a[i][j]]) {
                ++row;
                break;
            }
            else dd[a[i][j]] = 1;
        }
    }
    for (int j = 1; j <= n; ++j) {
        vector<int> dd(n + 1 ,0);
        for (int i = 1; i <= n; ++i) {
            if (dd[a[i][j]]) {
                ++col;
                break;
            }
            else dd[a[i][j]] = 1;
        }
    }
    int trace = 0;
    for (int i = 1; i <= n; ++i) trace += a[i][i];
    cout << trace << ' ' << row << ' ' << col;
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    int t; cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << '\n';
    }
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.










