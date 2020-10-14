#include<bits/stdc++.h>

using namespace std;

#define task "MOVE"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

const int N = 505;
const int inf = 2e9;
ll dp[N][N];
pair<int,int> a[N];
int n , k;
int caldist(pair<int,int> a, pair<int,int> b)
{
    return abs(a.first-b.first)+(a.second-b.second);
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) dp[i][j] = inf;
    }
    dp[1][0] = 0;

    for (int i = 2; i <= n ; ++i) {
        for (int j = 1; j < i; ++j) {
            for (int c = 0; c <= k; ++c) {

            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) cout << dp[i][j] << ' ';
        cout << endl;
    }
    cout << dp[n][k];
}









