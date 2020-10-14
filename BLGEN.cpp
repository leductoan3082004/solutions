#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "BLGEN"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull,ull> pii;

const ull oo = 2e9;
const ll inf = 1e15;
const ull N = 1005;

vector<ull> a, b;
ull dp[N][N];

bool prime(ull k)
{
    for (ull i = 2; i * i <= k; ++i) {
        if (k % i == 0) return 0;
    }
    return 1;
}
bool check(ull k)
{
    ull can2 = round(pow(k,0.5));
    ull can3 = round(pow(k,1.00/3.00));
    if (can2 * can2 == k || (can3 * can3 * can3 == k && prime(can3))) return 1;
    else return 0;

}
void add(string s, vector<ull> &q)
{
    ull sum = 0;
    for (ull i = 0; i < s.length(); ++i) {
        if (s[i] == ' ') {
            sum = 0;
            continue;
        }
        sum = (ull) sum * 10 + (s[i] - '0');
        if (check(sum)) q.push_back(sum);
    }
}
void solve()
{
    string s,t;
    getline(cin,s);
    getline(cin,t);
    add(s,a);
    add(t,b);
//    debug(a);
//    debug(b);
    for (ull i = 1; i <= a.size(); ++i) {
        for (ull j = 1; j <= b.size(); ++j) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = max(dp[i][j] , dp[i - 1][j - 1] + 1);
            else dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
        }
    }
    cout << dp[a.size()][b.size()];
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.










