#include<bits/stdc++.h>

using namespace std;

#define task "inverse_modulo"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;
int gcd(int a, int b , int &x, int &y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    else {
        int x1, y1;
        int ucln = gcd(b , a % b, x1, y1);
        x = y1;
        y = x1 - (a / b) * y1;
        return ucln;
    }
}
int inverse(int n, int m)
{
    int x,y;
    if (gcd(n,m,x,y) != 1) {
//        cout << x << ' ' << y << endl;
        return -1;
    }
//    cout << x << ' ' << y << endl;
    return (x % m + m ) % m;
}
int main()
{
    TL
//    freopen(task".inp","r",stdin);
//    freopen(task".out","w",stdout);
    cout << 1000 * inverse(100,3) % 3;
}









