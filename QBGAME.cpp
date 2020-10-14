/*https://bom.to/nxtvde2k1m4l*/
#include<bits/stdc++.h>
using namespace std;
#define task "QBGAME"
#define debug cout << '\n';
typedef pair<int,int> ii;
typedef long long ll;
const int N = 1e4+5;
const int num_of_mask = 1 << 8 + 5;
ll dp[N][num_of_mask],a[10][N],ans;
int m;
vector<int> state,mask[num_of_mask];
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
int get(int n, int i)
{
    return (n >> i ) & 1;
}
void solve(int c)
{
    for (int cur = 0; cur < state.size(); cur ++) {
        int cur_mask = state[cur];
        ll k = 0;
        for (int i = 0; i < 8; i ++) {
            if ((cur_mask >> i) & 1) {
                k += a[i][c];
            }
        }
        for (int i = 0 ; i < mask[cur_mask].size(); i ++)  {
            int pre_mask = mask[cur_mask][i];
            dp[c][cur_mask] = max(dp[c][cur_mask],dp[c-1][pre_mask] + k);
        }
        ans = max(ans,dp[c][cur_mask]);
    }
}
int main()
{
    init();
    cin >> m;
    ans = -1e15;
    for (int i = 0 ; i < 256; i ++)
    if ((i & (i >> 1)) == 0 ) {
        state.push_back(i);
        for (int j = 0; j < 256; j ++)
        if (((j & (j >> 1)) == 0) && ((j & i) == 0)) mask[i].push_back(j);
    }
    int ok = 0;
    for (int i = 0 ; i < 8; i ++)
    for (int j = 1; j <= m; j ++) {
        cin >> a[i][j];
        ans = max(ans,a[i][j]);
        if (a[i][j] > 0) ok = 1;
    }
    if (!ok) return cout << ans , 0 ;
    for (int j = 1; j <= m; j ++)  solve(j);

    cout << ans ;
}

