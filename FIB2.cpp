/*https://bom.to/nxtvde2k1m4l*/
#include<bits/stdc++.h>
using namespace std;
#define task "FIB2"
#define debug cout << '\n';
typedef pair<int,int> ii;
typedef long long ll;
ll a[50],f[50];
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
long long cal (int i, int k)
{
    if ( k == a[i] ) return f[i];
    if ( k <= a[i-2] ) return cal(i-2,k);
    if ( k > a[i-2] ) return cal(i-2,a[i-2]) + cal(i-1,k-a[i-2]);
}
int main()
{
    /// a ,b, a_b ,b_ab ,ab_bab ,bab_abbab
    init();
    f[0] = 1;
    f[1] = 0;
    for (int i = 2 ; i <= 46; i ++) f[i] = f[i-1] + f[i-2];
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= 46; i ++)  a[i] = a[i-1] + a[i-2];
    int t; cin >> t;
    while (t-- ) {
        int n,k;
        cin >> n >> k;
        cout << cal(n,k) << '\n';
    }
}
