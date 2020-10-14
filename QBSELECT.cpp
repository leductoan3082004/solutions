/*https://bom.to/nxtvde2k1m4l*/
#include<bits/stdc++.h>
using namespace std;
#define task "QBSELECT"
#define debug cout << '\n';
typedef pair<long long ,long long > ii;
const long long  N = 10005;
long long  m,a[10][N],dp[N][20],ans;
long long  h[] = {0,1,2,4,5,8,9,10};
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
long long  get(long long  n, long long  i)
{
    return (n >> i ) & 1;
}
bool check(long long  state1, long long  state2)
{
    for (long long  i = 0; i < 4; i ++)
    if (get(state1,i) == 1 && get(state1,i) == get(state2,i)) return false;
    return true;
}
/// dp[j][state] column j and with state
void sol(long long  c)
{
    for (long long  x = 0; x < 8; x ++)
    for (long long  y = 0; y < 8; y ++)
    if (check(h[x],h[y])) {
        long long  cur_mask = h[x];
        long long  pre_mask = h[y];
        long long  sum = 0;
        for (long long  i = 0; i < 4 ; i ++)
        if (get(cur_mask,i)) sum += a[i][c];
        dp[c][cur_mask] = max(dp[c][cur_mask] , dp[c-1][pre_mask] + sum);
        if (c == m ) ans = max(ans,dp[c][cur_mask]);
    }
}
int  main()
{
    init();
    cin >> m;
    ans = -1e9;
    int ok = 0;
    for (long long  i = 0; i < 4; i ++)
    for (long long  j = 1; j <= m; j ++) {
        cin >> a[i][j];
        ans = max(ans,a[i][j]);
        if (a[i][j] > 0) ok = 1;
    }
    if (!ok ) return cout << ans , 0;
    for (long long  j = 1 ; j <= m; j ++) sol(j);
    cout << ans;
}
