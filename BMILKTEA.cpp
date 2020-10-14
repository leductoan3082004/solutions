#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "task"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mod=442441073;
const int mxn=1005;
string s[mxn];
int dp[mxn][mxn][4],n,m;

void add(int &a, int b)
{
    a=(a+b)%mod;
}
void solve()
{
    cin >> n >> m;
    for (int i=1; i<=n; ++i) {
        cin >> s[i];
        s[i]=" "+s[i];
    }
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            dp[i][j]=0;
        }
    }
    /// 0 : tra, 1: sua , 2:tra,sua, 3: tra, sua , bot nang
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            for (int k=0; k<=3; ++k) {
                add(dp[i][j][k],dp[i-1][j][k]+dp[i][j-1][k]);
            }
            if (s[i][j]=='T') {
                add
            }
        }
    }
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    int tc;
    cin >> tc;
    while (tc--)
    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.











