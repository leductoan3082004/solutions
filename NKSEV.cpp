#include<bits/stdc++.h>

using namespace std;

#define task "NKSEV"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

const int N = 400005;
const int mod = 1337377;

int End[N],T[N][30],dp[N],cnt;
string s;
void add(string S)
{
    int root = 0;
    for (int i = 0; i < S.length(); ++i) {
        int c = S[i] - 'a';
        assert(0 <= c && c < 26);
        if (T[root][c] == 0) T[root][c] = ++cnt;
        root = T[root][c];
    }
    ++End[root];
}

void tim(int p)
{
    /// s[p - 100 + 1....p]
    int root = 0;
    for (int i = p; i >= max(1,p - 100 + 1); --i) {
        int c = s[i] - 'a';
        assert(0 <= c && c < 26);
        if (T[root][c] == 0) return ;
        root = T[root][c];
        if (End[root]) dp[p] = (dp[p] + dp[i - 1]) % mod;
    }
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> s;
    s = ' ' + s;
    int n = s.length() - 1;
    int m; cin >> m;
    for (int i = 1; i <= m; ++i) {
        string t; cin >> t;
        reverse(t.begin(),t.end());
        add(t);
    }
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        tim(i);
    }
    cout << dp[n];
}












