#include<bits/stdc++.h>
using namespace std;
#define task "SUBSTR"
typedef pair<int,int> ii;
typedef long long ll;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
int main()
{
    init();
    string s;
    cin >> s;
    s = " " + s;
    int n = s.length() -1 ;
    int l = 1, L = 0, R = 0, max_len = 0 ;
    vector<int> dd(10000,0);
    for (int r = 1; r <= n; ++ r) {
        ++dd[s[r]];
        while (dd[s[r]] > 1) --dd[s[l++]];
        if (max_len < r - l + 1) {
            L = l;
            max_len = r - l + 1;
        }
    }
    cout << L << ' ' << max_len;
}





