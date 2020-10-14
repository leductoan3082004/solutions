/*https://bom.to/nxtvde2k1m4l*/
#include<bits/stdc++.h>
using namespace std;
#define task "GOLD"
typedef pair<int,int> ii;
typedef long long ll;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
ll a[5] = {1,1,2,6,4} , n;
ll Pow(ll a)
{
    if (a % 4 == 0) return 6;
    if (a % 4 == 3) return 8;
    if (a % 4 == 2) return 4;
    if (a % 4 == 1) return 2;
}
ll cal(ll n)
{
    if (n < 2) return 1;
    else return (Pow(n / 5) * cal(n / 5) * a[ n % 5 ]) % 10;
}
int main()
{
    init();
    cin >> n;
    cout << cal(n);
}





