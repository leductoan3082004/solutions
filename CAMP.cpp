#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "CAMP"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<ll,ll> pii;

const ll mxn=1005;

pii a[mxn],b[mxn];
ll n,m,dp[mxn][mxn][2];
ll SQR(ll a)
{
    return a*a;
}
ll dist(pii a, pii b)
{
    return SQR(a.first-b.first)+SQR(a.second-b.second);
}
void solve()
{
    cin >> n >> m;
    for (ll i=1; i<=n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    for (ll i=1; i<=m; ++i) {
        cin >> b[i].first >> b[i].second;
    }

    for (ll i=0; i<=n; ++i) {
        for (ll j=0; j<=m; ++j) {
            dp[i][j][0]=dp[i][j][1]=(ll)1e15;
        }
    }
    /// 0 n , 1 m
    dp[1][0][0]=0;
    dp[1][1][1]=dist(a[1],b[1]);
    for (int j=2; j<=m; ++j) {
        dp[1][j][1]=dp[1][j-1][1]+dist(b[j],b[j-1]);
    }
    for (ll i=2; i<=n; ++i) {
        for (ll j=0; j<=m; ++j) {
            if (i>0) dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][0]+dist(a[i],a[i-1]));
            if (i>0) dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][1]+dist(b[j],a[i]));
            if (j>0) dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+dist(b[j],b[j-1]));
            if (j>0) dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][0]+dist(a[i],b[j]));
        }
    }

    cout << dp[n][m][0];
}
int main()
{
    TL
//    freopen(task".inp","r",stdin);
//    freopen(task".out","w",stdout);

    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.











