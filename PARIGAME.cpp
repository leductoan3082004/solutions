#include<bits/stdc++.h>
using namespace std;
#define task "parigame"
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

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
const int N=505;
int n,a[N][N],f[N][N],g[N][N],dp[N][N];
void solve()
{
        read(n);
        for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j) read(a[i][j]);

        for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j) f[i][j]=f[i][j-1]+a[i][j];

        for(int j=1;j<=n;++j)
        for(int i=1;i<=n;++i) g[i][j]=g[i-1][j]+a[i][j];

        for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j) dp[i][j]=0;

        for(int i=1;i<=n;++i)
        {
                for(int j=1;j<=n;++j)
                {
                        if(!dp[i-1][j]&&f[i][j]%2==0) dp[i][j]=1;
                        if(!dp[i][j-1]&&g[i][j]%2==0) dp[i][j]=1;
                }
        }
        if(dp[n][n]) cout<<"YES\n";
        else cout<<"NO\n";
}
int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0);
        if(fopen(task".inp","r"))
        {
                freopen(task".inp","r",stdin);
                freopen(task".out","w",stdout);
        }
        int t;
        read(t);
        while(t--) solve();
}



