#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "ROBOT1100"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int N=1005;
int n,m,dp[N][N],a[N],b[N];
void solve()
{
    cin >> n >> m;
    for (int i=1; i<=n; ++i) cin >> a[i];
    for (int i=1; i<=m; ++i) cin >> b[i];

    for (int i=0; i<=n; ++i) {
        for (int j=0; j<=m; ++j) {
            dp[i][j]=2e9;
        }
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    dp[0][0]=0;
    for (int i=1; i<=n; ++i) {
        for(int j=0; j<=m; ++j) {
            if (i>0) dp[i][j]=dp[i-1][j];
            if (i>0&&j>0) dp[i][j]=min(dp[i][j],dp[i-1][j-1]+abs(a[i]-b[j]));
        }
    }
//    for (int i=1; i<=n; ++i) {
//        for (int j=0; j<=m; ++j) cout << dp[i][j] << ' ';
//        cout << endl;
//    }
    cout << dp[n][m];
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.











