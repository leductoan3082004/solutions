#include<bits/stdc++.h>

using namespace std;

#define task "LEM3"
#define debug cout << '\n';
typedef pair<int,int> ii;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
const int number_of_mask = (1 << 16) + 5;
long long dp[20][number_of_mask],a[20][20],n;
int get(int n, int i)
{
    return ( n >> i ) & 1;
}
int off (int n, int i )
{
    return n & (~ ( 1 << i)) ;
}
void solve(int mask)
{
    for (int i = 0; i < n ; i++)
    if (get(mask,i)) {
        int pre_mask = off(mask,i);
        for (int j = 0; j < n ; j ++)
        if (get(pre_mask,j)) dp[i][mask] = min(dp[i][mask],dp[j][pre_mask] + a[j][i]);
    }
}
int main()
{
    /// 001 010 011 100 101 110 111
    init();
    cin >> n;
    for (int i = 0; i < n; i ++)
    for (int j = 0; j < n; j ++)  cin >> a[i][j];

    for (int i = 0; i < n; i ++)
    for (int j = 0; j <= (1 << n ) ; j ++)  dp[i][j] = 1e9;

    for (int i = 0; i < n; i ++) dp[i][1 << i] = 0;

    for (int i = 1; i < (1 << n) ; i ++) {
        solve(i);
    }
    long long  ans = 1e9;
    for (int i = 0; i < n; i ++)  ans = min(ans,dp[i][(1 << n) -1]);
    cout << ans;
}

