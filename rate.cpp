#include<bits/stdc++.h>
using namespace std;
#define task "rate"
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define BIT(x, i) (((x) >> (i)) & 1)
#define lb lower_bound
#define ub upper_bound
#define lla(v) (v).begin(),(v).end()
#define zs(v) int((v).size())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ar array
#define endl '\n'
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1000000007; /// 998244353
const int base=311;
const int N=3e5+5;

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
int a[N],n,k;
ld b[N];
bool check(ld val)
{
    for(int i=1;i<=n;++i) b[i]=a[i]-val,b[i]+=b[i-1];
    ld mn=1e9;
    for(int i=k;i<=n;++i)
    {
        mn=min(mn,b[i-k]);
        if(b[i]-mn>=0) return 1;
    }
    return 0;
}
void solved()
{
    read(n); read(k);
    int mx=0;
    for(int i=1;i<=n;++i) read(a[i]),mx=max(mx,a[i]);
    ld l=0, r=mx;
    for(int i=1;i<=40;++i)
    {
        ld mid=(l+r)/2.00;
        if(check(mid)) l=mid;
        else r=mid;
    }
    cout<<fixed<<setprecision(6)<<l;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    solved();
}








