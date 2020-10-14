#include<bits/stdc++.h>

using namespace std;

#define task "CHAIN2"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

const int N = 250005;
string s[N];
int n , cnt, T[N][30], dp[N];

void add(string s)
{
    int root = 0;
    for (int i = 0; i < s.length(); ++i) {
        int c = s[i] - 'a';
        assert(0 <= c && c < 26);
        if (T[root][c] == 0) T[root][c] = ++cnt;
        int pre_root = root;
        root = T[root][c];
        dp[root] = max(dp[root],dp[pre_root]);
    }
    ++dp[root];
}

int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        add(s[i]);
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) ans = max(ans,dp[i]);
    cout << ans;
}










