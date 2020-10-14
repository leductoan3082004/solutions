#include<bits/stdc++.h>

using namespace std;

#define task "HELPPM"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int N = 505;

int n , m , k;
ll a[N][N];

int main()
{
    TL
//    freopen(task".inp","r",stdin);
//    freopen(task".out","w",stdout);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            a[i][j] += a[i][j - 1];
        }
    }
    int ax = -1, ay = -1, bx = -1, by = -1, area = 2e9;
    for (int L = 1; L <= m; ++L) {
        for (int R = L; R <= m; ++R) {
            int j = 1; ll sum = 0;
            for (int i = 1; i <= n ; ++i) {
                sum += a[i][R] - a[i][L - 1];
                while (sum - (a[j][R] - a[j][L - 1]) >= k && j <= i) {
                    sum -= (a[j][R] - a[j][L - 1]);
                    ++j;
                }

                if (sum >= k && area > (i - j + 1) * (R - L + 1)) {
                    area = (i - j + 1) * (R - L + 1);
                    ax = j; ay = L; bx = i; by  = R;
                }
            }
        }
    }
    if (ax == -1) cout << -1;
    else {
        cout << area << '\n';
        cout << ax << ' ' << ay << ' ' << bx << ' ' << by;
    }

    return 0;
}










