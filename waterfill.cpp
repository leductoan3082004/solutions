#include<bits/stdc++.h>
using namespace std;
#define task "waterfilll"
#define lwb lower_bound
#define upb upper_bound
#define ar array
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
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
const int N=1e5+5;
int n,k,a[N];

bool ck1(ll t)
{
        ll thua=0;
        for(int i=1;i<=n;++i) {
                if(i==n&&t*k+thua<a[i]) return 0;
                thua+=t*k-a[i];
                thua=max(thua,0LL);
        }
        return 1;
}
bool ck2(ll t)
{
        ll thua=0;
        for(int i=1;i<=n;++i) {
                if(t*k+thua<a[i]) return 0;
                thua=thua+t*k-a[i];
        }
        return 1;
}
void solve()
{
        read(n); read(k);
        ll sum=0;
        int mx=0;
        for(int i=1;i<=n;++i) read(a[i]), mx=max(mx,a[i]);
        ll l=1, r=(mx+k)/k,ans1,ans2;
//        cout<<ck1(2)<<endl;
        while(l<=r) {
                ll mid=(l+r)>>1;
                if(ck1(mid)) {
                        r=mid-1;
                        ans1=mid;
                }
                else l=mid+1;
        }
        l=1, r=(mx+k)/k;
        while(l<=r) {
                int mid=(l+r)>>1;
                if(ck2(mid)) {
                        r=mid-1;
                        ans2=mid;
                }
                else l=mid+1;
        }
        cout<<ans1<<" "<<ans2;
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





