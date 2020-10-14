#include<bits/stdc++.h>
using namespace std;

#define task "bhouse"
#define fi first
#define se second
#define fore(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define ford(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)

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
const int mxn=1005;
int n,m,a[mxn][mxn],p[mxn][mxn],h[mxn];
ll ans=0,f[mxn][mxn];
deque<int> q;
void solve()
{
    read(n); read(m);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            read(a[i][j]);
            if(a[i][j]!=a[i][j-1]) p[i][j]=j-1;
            else p[i][j]=p[i][j-1];
        }
    }

//    cout<<p[3][1]<<'\n';
    for(int i=1;i<=n;++i)
    {
        while(!q.empty()) q.pop_back();
        for(int j=1;j<=m;++j)
        {
            if(a[i][j]==a[i-1][j]) ++h[j];
            else h[j]=1;
            while(!q.empty()&&a[i][q.front()]!=a[i][j]) q.pop_front();
            while(!q.empty()&&h[q.back()]>=h[j]) q.pop_back();
            int pos=0;
            if(!q.empty()) pos=q.front();
            else pos=p[i][j];
            if(a[i][j]==a[i][pos]) f[i][j]=f[i][pos]+h[j]*(j-pos);
            else f[i][j]=h[j]*(j-pos);
            ans+=f[i][j];
            q.push_back(j);
        }
    }
    cout<<ans;
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


