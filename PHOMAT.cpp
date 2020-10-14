/*https://bom.to/nxtvde2k1m4l*/
#include<bits/stdc++.h>
using namespace std;
#define task "PHOMAT"
#define uwu cout << '\n';
#define debug2(a,b) cout << a << ' ' << b << '\n'
#define debug3(a,b,c) cout << a << ' ' << b << ' ' << c << '\n'
#define debug4(a,b,c,d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'
typedef pair<int,int> ii;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
const int N = 105;
ii a[N];
int n,m,dp[N][N];
int main()
{
    init();
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)  cin >> a[i].first >> a[i].second;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i ++)
    for (int j = 0; j <= m; j ++) {
        dp[i][j] = dp[i-1][j];
        if (j - a[i].first >= 0 )
        dp[i][j] = max(dp[i][j],dp[i-1][j-a[i].first] + a[i].second);
    }
    cout << dp[n][m];
}




