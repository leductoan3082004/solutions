#include<bits/stdc++.h>

using namespace std;

#define task "sorrow"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

const int N = 2e6 + 100000;
int pre[N],T[N][30],cnt;
void add(string s)
{
    int root = 0;
    for (int i = 0; i < s.length(); ++i) {
        int c = s[i] - 'a';
        if (T[root][c] == 0) T[root][c] = ++cnt;
        root = T[root][c];
        pre[root] ++;
    }
}
void let(string s)
{
    int root = 0;
    for (int i = 0; i < s.length(); ++i) {
        int c = s[i] - 'a';
        if (T[root][c] == 0) {
            cout << 0 << '\n';
            return;
        }
        root = T[root][c];
    }
    cout << pre[root] << '\n';
    return;
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    int n;
    cin >> n;
    while (n--) {
        string t;
        string s;
        cin >> t  >> s;
        if (t == "add") add(s);
        else let(s);
    }
}










