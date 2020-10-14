#include<bits/stdc++.h>

using namespace std;

#define task "word_query"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

const int N = 1e6 + 5;
int T[N][30],cnt,pre[N];
void add(string s)
{
    int root = 0;
    for (int i = 0; i < s.length(); ++i) {
        int c = s[i] - 'a';
        assert(0 <= c && c < 26);
        if (T[root][c] == 0) T[root][c] = ++cnt;
        root = T[root][c];
        ++pre[root];
    }
}
int let(string s)
{
    int root = 0;
    for (int i = 0; i < s.length(); ++i) {
        int c = s[i] - 'a';
        assert(0 <= c && c < 26);
        if (T[root][c] == 0) return 0;
        root = T[root][c];
    }
    return pre[root];
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    int n , q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        string s; cin >> s;
        add(s);
    }

    while (q--) {
        string s;
        cin >> s;
        cout << let(s) << '\n';
    }
}










