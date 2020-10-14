/*https://bom.to/nxtvde2k1m4l*/
#include<bits/stdc++.h>
using namespace std;
#define task "FIB2"
#define debug cout << '\n';
typedef pair<int,int> ii;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".ans","w",stdout);
}
int main()
{
    init();
    int t;
    vector < string > a (45);
    a[0] = 'a';
    a[1] = 'b';
    for (int i = 2; i <= 20; i ++)
        a[i] = a[i-2] + a[i-1];

    cin >> t;
    while (t--) {
        int n,k,ans = 0;
        cin >> n >> k;
        for (int i = 0 ; i < k; i ++)
        if (a[n][i] == 'a') ans ++ ;
        cout << ans << '\n';
    }
}
