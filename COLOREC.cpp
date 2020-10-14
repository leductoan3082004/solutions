#include<bits/stdc++.h>
using namespace std;
#define task "colorec"
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
int a[500][500];
int n;
void solve()
{
        read(n);
        for(int i=1;i<=n;++i)
        {
            int u,v,c;
            read(u); read(v); read(c);
            a[u+200][v+200]=c;
        }
        int ans=0;
        for(int i=0;i<=400;++i)
        {
                for(int j=i+1;j<=400;++j)
                {
                        vector<int> cnt(20,0);
                        for(int r=0;r<=400;++r)
                        {
                                if(a[i][r]!=0&&a[j][r]!=0&&a[i][r]!=a[j][r])
                                {
                                        int mask1=(1<<(a[i][r]-1));
                                        int mask2=(1<<(a[j][r]-1));
                                        int mask=(mask1|mask2);
                                        ans+=cnt[15-mask];
                                        ++cnt[mask];
                                }
                        }
                }
        }
        write(ans);
}
int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0);
        if(fopen(task".inp","r"))
        {
                freopen(task".inp","r",stdin);
                freopen(task".out","w",stdout);
        }
        solve();
}



