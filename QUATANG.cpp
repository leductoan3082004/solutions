#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "task"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;
const int mxn=205, tt=90000;
int n,a[mxn],b[mxn],dp[mxn][400005],sum;

void trace(int i, int s)
{
    vector<int> ans1,ans2;
    while (i>=1) {
        if (dp[i][s+tt]==dp[i-1][s+tt]) {
            --i;
            continue;
        }
        else {
            if (dp[i-1][tt+s-a[i]]+b[i]==dp[i][tt+s]) {
                s-=a[i];
                ans1.push_back(i);
            }
            else
            if (dp[i-1][tt+s+a[i]]-b[i]==dp[i][tt+s]) {
                s+=a[i];
                ans2.push_back(i);
            }
            --i;
        }

    }
    cout << "YES\n";
    cout << ans1.size() << ' ';
    for (int i : ans1) cout << i << ' ';
    cout << '\n';
    cout << ans2.size() << ' ';
    for (int i : ans2) cout << i << ' ';
}
void solve()
{
    cin >> n;
    for (int i=1;i<=n;++i) {
        cin >> a[i];
        sum+=a[i];
    }
    for (int i=1;i<=n;++i) {
        cin >> b[i];
    }
    for (int i=0;i<=n;++i) {
        for (int j=-2*sum;j<=2*sum;++j) {
            dp[i][j+tt]=2e9;
        }
    }
    dp[0][tt]=0;
    for (int i=1;i<=n;++i) {
        for (int j=-sum;j<=sum;++j) {
            dp[i][j+tt]=dp[i-1][j+tt];
            dp[i][j+tt]=min(dp[i][j+tt],dp[i-1][j-a[i]+tt]+b[i]);
            if (dp[i-1][j+a[i]+tt]!=2e9)
            dp[i][j+tt]=min(dp[i][j+tt],dp[i-1][j+a[i]+tt]-b[i]);
        }
    }
    for (int s=1;s<=sum;++s) {
        if (dp[n][tt+s]<0) {
            trace(n,s);
            return;
        }
    }
    cout << "NO\n";
}
int main()
{
#ifdef LOCAL
    freopen("in","r",stdin);
    freopen("out","w",stdout);
//    freopen(task".inp","r",stdin);
//    freopen(task".out","w",stdout);
#endif

    TL
    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.











