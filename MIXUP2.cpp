/*https://bom.to/nxtvde2k1m4l*/
#include<bits/stdc++.h>
using namespace std;
#define task "MIXUP2"
#define debug cout << '\n';
typedef pair<int,int> ii;
const int number_of_mask = (1 << 16) + 5;
unsigned long long dp[20][number_of_mask];
int a[20],n,k;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
int get(int n, int i)
{
    return ( n >> i ) & 1;
}
int off (int n, int i)
{
    return n & (~ ( 1 << i )) ;
}
void solve(int mask)
{
    for (int i = 0; i < n; i ++)
    if (get(mask,i) == 1) {
        int pre_mask = off(mask,i);

        for (int j = 0; j < n ; j ++)
        if (get(pre_mask,j) == 1 && abs(a[i] - a[j]) > k ) dp[i][mask] += dp[j][pre_mask];
    }
}
int main()
{
    init();
    cin >> n >> k;

    for (int i = 0; i < n; i ++) cin >> a[i];

    for (int i = 0; i < n; i ++)  dp[i][1 << i] = 1;
    for (int i = 0; i < (1 << n) ; i ++) solve(i);

    unsigned long long ans = 0;

    for (int i = 0; i < n ; i ++)  ans += dp[i][(1 << n ) - 1];

    cout << ans;
}

