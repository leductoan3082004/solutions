#include<bits/stdc++.h>

using namespace std;

#define task "trees"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

const int mod  = 1e9 + 7;
const int N = 205;
ll ans = 0, dp[N][N];
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);


    string s;
    cin >> s;
    s = " " + s;
    int n = s.length() - 1;
    for (int k = 1; k <= n; ++k) {
        string s1 = s.substr(1,k);
        string s2 = s.substr(k + 1,s.length());
        int n1 = s1.length(), n2 = s2.length();
        for (int i = 0; i <= n1; ++i) {
            for (int j = 0; j <= n2; ++j) dp[i][j] = 0;
        }
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + 1) % mod;
                else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]) % mod;
            }
        }
        ans = (ans + dp[n1][n2]) % mod;
    }
    cout << ans;
}










