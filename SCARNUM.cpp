#include<bits/stdc++.h>

using namespace std;

#define task "SCARNUM"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    int m; cin >> m;
    while (m--) {
        int n;
        cin >> n;
        if ( n % 2 == 0 || n % 5 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}










