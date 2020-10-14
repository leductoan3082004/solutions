#include<bits/stdc++.h>

using namespace std;

#define task "FCHAR"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;
const int N = 1e5 + 5;
vector<vector<int> > dd(N, vector<int> (26,0));
int m;
bool check(int l, int r)
{
    for (int i = 0; i < 5; ++i) {
        if (dd[r][i] - dd[l - 1][i] < m) {
            return false;
        }
    }
    return true;
}
int bs(int l, int r)
{
    int L = l;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(L,mid)) {
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    return ans;
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    string s; cin >> s;
    cin >> m;
    s = " " + s;
    int n = s.length() - 1;
    for (int i = 1; i <= n; ++i) {
        dd[i] = dd[i - 1];
        int c = s[i] - 'a';
        dd[i][c] ++;
    }
    int ans = 1e9;
    for (int i = 1; i <= n ; ++i) {
        int k = bs(i,n);
        if (k == -1) continue;
        ans = min(ans, k - i + 1);
    }
    if (ans == 1e9) cout << -1;
    else cout << ans;
}










