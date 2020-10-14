#include<bits/stdc++.h>

using namespace std;

#define task "LGDGONME"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

vector<int> xuli(vector<int> a, vector<int> b)
{
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {

        }
    }
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n >> m;
    for (int tc = 1; tc <= m; ++tc) {
        vector<int> a;
        a.resize(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        if (tc == 1) {
            pre = a;
            continue;
        }
        pre = xuli(pre,a);
    }
}










