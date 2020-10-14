#include<bits/stdc++.h>

using namespace std;

#define task "QBPAL"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

ll dp[200][200];
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    string a ,b;
    cin >> a;
    b = a;
    reverse(b.begin(),b.end());
    int n = a.size();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + 1;
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
    cout << dp[n][n];
}










