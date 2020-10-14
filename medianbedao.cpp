#include<bits/stdc++.h>
using namespace std;
#define task "median"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define pf pop_front
#define mp make_pair
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(),(v).end()
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
const int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const int dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1000000007; /// 998244353
const int base=311;
const int N=1e6+5;

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

int n,x,a[N];
void biot()
{
    read(n); read(x);
    for(int i=1;i<=n;++i) read(a[i]);

    sort(a+1,a+n+1);

    int l,r;
    for(int i=1;i<=n;++i) if(a[i]==x) r=i;
    for(int i=n;i>=1;--i) if(a[i]==x) l=i;

    int ans=0;
    int pos=(n+1)/2;
    if(pos>=l&&pos<=r) cout<<0;
    else if(l>=pos)
    {

        while(l>(n+1)/2) ++n, ++ans;
        cout<<ans;
    }
    else if(r<=pos)
    {
        while(r<(n+1)/2) ++n, ++r, ++ans;
        cout<<ans;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    biot();
    return 0;
}
