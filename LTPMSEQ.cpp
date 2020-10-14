#include<bits/stdc++.h>

using namespace std;

#define task "LTPMSEQ"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

const int N = 1500000;
int cnt,n,T[N][50],End[N];
string s[N];
void add(string s)
{
    int root = 0;
    for (int i = 0; i < s.length(); ++i) {
        int c = (s[i] - 'a');
//        assert(0 <= c && c < 26);
        if (T[root][c] == 0) T[root][c] = ++cnt;
        root = T[root][c];
    }
    ++End[root];
}
int find(string s)
{
    int root = 0;
    for (int i = 0; i < s.length(); ++i) {
        int c = (s[i] - 'a');
//        assert(0 <= c && c < 26);
        root = T[root][c];
    }
    return End[root];
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
    for (int i = 1; i <= n; ++i) {
        if (find(s[i]) & 1) return cout << s[i] , 0;
    }
}










