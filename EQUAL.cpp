#include<bits/stdc++.h>

using namespace std;

#define task "EQUAL"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

int main()
{
    TL
//    freopen(task".inp","r",stdin);
//    freopen(task".out","w",stdout);

    int t; cin >> t;
    while (t--) {
        int a , b;
        cin >> a >> b;
        if (a <= b) swap(a,b);
        if (a == b) cout << "YES";
        else
        if ((a + b) % 2 == 1) cout << "NO";
        else
        if (a == 1 ||  b == 1) cout << "NO";
        else {
            b += a / 2;
            a -= a / 2;
            if (a == 1 || b == 1) cout << "NO";
            else if (a == b) cout << "YES";
            else cout << "NO";
        }
        cout << endl;
    }
}










