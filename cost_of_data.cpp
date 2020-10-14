#include<bits/stdc++.h>

using namespace std;

#define task "cost_of_data"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

const int N = 1e6 + 5;
int T[N][30],cnt;
void add(string s)
{
    int root = 0;
    for (int i = 0 ; i < s.length(); ++i) {
        int c = s[i] - 'a';
        assert(0 <= c && c < 26);
        if (T[root][c] == 0) T[root][c] = ++cnt;
        root = T[root][c];
    }
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        add(s);
    }
    cout << cnt + 1;
}










