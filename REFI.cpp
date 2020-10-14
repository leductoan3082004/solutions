#include<bits/stdc++.h>

using namespace std;

#define task "REFI"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

const int N = 1e5 + 5;
ll dp[N][20];
const ll MOD =  998244353;
void add(ll &res, ll k)
{
    res = ( res + k ) % MOD;
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    string s;
    cin >> s;
    s = ' ' + s;
    int n = s.length() - 1;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (s[i] != '?') {
            for (int mod = 0; mod < 17; ++mod) {
                int digit = (mod * 10 + s[i] - '0') % 17;
                add(dp[i][digit],dp[i - 1][mod]);
            }
        }
        else {
            for (int mod = 0; mod < 17; ++mod) {
                for (int j = 0; j <= 9; ++j) {
                    int digit = (mod * 10 + j ) % 17;
                    add(dp[i][digit],dp[i - 1][mod]);
                }
            }
        }
    }
    cout << dp[n][5];
}










