#include<bits/stdc++.h>

using namespace std;

#define task "bstring"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
int n;
string s;
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n >> s;
    s = ' ' + s;
    int d1 = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '0') ++d1;
    }
    int d2 = d1,ans1 = 0,ans2 = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '1' && d1 > 0) {
            d1--;
            ans1 ++;
        }
        else d1--;
    }

    for (int i = n; i >= 1; --i) {
        if (s[i] == '1' && d2 > 0) {
            d2 -- ;
            ans2 ++;
        }
        else d2 --;
    }
    cout << min(ans1,ans2) ;
}











