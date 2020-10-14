#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "REPLACE"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int oo = 2e9;
const ll inf = 1e15;
const int N = 1e6 + 5;

int dd[N] , ff[N] , a[N];

void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    s = ' ' + s;
    t = ' ' + t;
    int i = n, j = m;
    while (i >= 1 && j >= 1) {
        if (s[i] == t[j]) {
            ff[n - i + 1] = 1;
            --i;
            --j;
        }
        else break;
    }
    i = 1; j = 1;
    while (i <= n && j <= m) {
        if (s[i] == t[j]) {
            dd[i] = 1;
            i ++;
            j ++;
        }
        else break;
    }
    for (int i = 1; i <= n; ++i) {
        a[i] += a[i - 1] + s[i] - '0';
    }
    dd[0] = 1; ff[n + 1] = 1;
    int l , r;
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        int sum = 0;
        for (int j = i; j <= min(m,i + 7); ++j) {
            int pre = i - 1;
            int suf = m - j;
            sum = sum * 10 + (t[j] - '0');
            if (i == 2 && j == 3) {
//                cout << pre << ' ' << suf << endl;
            }
            if (dd[pre] && ff[suf] && a[n - suf] - a[pre] == sum)
                if (ans < n - pre - suf) {
                    ans = max(ans,n - pre - suf);
                    l = pre + 1;
                    r = n - suf;
                }
                else if (ans == n - pre - suf) {
                        if (pre + 1 <= l) {
                            l = pre + 1;
                            r = n - suf;
                        }
                }
        }
    }
    cout << l << ' ' << r;
}
int main()
{
    TL
//    freopen(task".inp","r",stdin);
//    freopen(task".out","w",stdout);

    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.










