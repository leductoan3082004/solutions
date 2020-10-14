/*https://bom.to/nxtvde2k1m4l*/
#include<bits/stdc++.h>
using namespace std;
#define task "PRIMECOUNT"
#define debug cout << '\n';
typedef pair<int,int> ii;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
long long cal (int l, int r)
{
    vector<int> IsPrime(r - l + 5, 1);
    l = max(2,l);

    for (int i = 2; i * i <= r ; i ++ )  {
        int k = (l / i) * i ;
        if (k < l) k += i;
        for (int j = max(i*i,k) ; j <= r; j += i) IsPrime[j - l] = 0;
    }

    int ans = 0;
    for (int i = l ; i <= r; i ++) {
        ans += IsPrime[i - l];
    }

    return ans;
}
int main()
{
    init();
    int t;
    cin >> t;
    while (t--) {
        int u,v;
        cin >> u >> v;
        cout << cal(u,v) << '\n';
    }
}
