#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const ld inf = 1e14;
const int N = 1e3+5;
struct two
{
    int u,v;
    ld w;
};
template <typename T>
inline void read(T& x)
{
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' | c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}
vector<two> a;
int n,m;
bool check(ld k)
{
    vector<ld> d(n+1,inf);
    d[a[0].u] = 0;
    for (int j = 1; j<n; j++)
    for (int i=0; i<a.size(); i++) {
        int u = a[i].u, v = a[i].v ;
        ld w = a[i].w;
        if (d[u] != inf && d[v] > d[u] + w - k) d[v] = d[u] + w - k;
    }

    for (int i=0; i<a.size(); i++) {
        int u = a[i].u, v = a[i].v ;
        ld w = a[i].w;
        if (d[u] != inf && d[v] > d[u] + w - k) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    read(n); read(m);
    while (m-- ) {
        int u,v;
        int w;
        read(u); read(v);read(w);
        a.push_back({u,v,w});
    }
    ld l = 0.0, r = 1e9, ans = -1.00;
    for(int i=1;i<=40;++i) {
        ld mid=(l+r)/2.00;
        if (check(mid)) {
            l = mid;
            ans = mid;
        }
        else r = mid;
    }
    if (ans < 1e9-2) cout<<fixed<<setprecision(2)<<ans;
    else cout << "NO TOUR";
}

