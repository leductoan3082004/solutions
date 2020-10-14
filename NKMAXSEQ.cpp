/*https://bom.to/nxtvde2k1m4l*/
#include<bits/stdc++.h>
using namespace std;
#define task "NKMAXSEQ"
#define debug(a) cout << a << '\n'
#define uwu cout << '\n';
typedef pair<long long ,long long > ii;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
const long long  N = 1e5+5;
ii a[N];
long long  main()
{
    init();
    long long  n,p;
    cin >> n ;
    p = 1;
    a[0] = {0,0};
    for (long long  i = 1; i <= n; i ++) {
        cin >> a[i].first ;
        a[i].second = i;
        a[i].first += a[i-1].first;
    }
    sort(a,a+n+1);

    //for (long long  i = 1; i <= n; i ++) cout << a[i].first << ' ' << a[i].second << '\n';
    long long  min_index = 1e9, L = 0, R = 0, ans = -1;

    long long  j = -1;
    for (long long  i = 0; i <= n; i ++) {
        while (j <= n && a[i].first -  a[j+1].first >= p) {
            min_index = min(min_index,a[++j].second);
        }
        if (a[i].second - min_index  >  ans) {
            ans = a[i].second - min_index;
            L = min_index + 1;
            R = a[i].second;
        }
        //debug(min_index);
    }
//    cout << ans;
    cout << L << ' ' << R;
}
