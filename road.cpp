#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "road"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

template <typename T>
inline void Read(T& x)
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
inline void Write(T x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}
typedef long long ll;
typedef pair<ll,ll> pii;

const int mxn=100005;
int n,k;
pii a[mxn];
void solve()
{
    Read(n); Read(k);
    for(int i=1;i<=n;++i) {
        Read(a[i].fi);
        a[i].fi-=k;
        a[i].se=i;
        a[i].fi+=a[i-1].fi;
    }

    sort(a,a+n+1);
//    for(int i=0;i<=n;++i) cout<<a[i].fi<<' '<<a[i].se<<'\n';
    int i=0;
    int ans=0,l=0;
    while(i<=n) {
        int j=i;
        while(j<n&&a[j+1].fi==a[i].fi) ++j;
        if(a[j].se-a[i].se>ans) {
            ans=a[j].se-a[i].se;
            l=a[i].se+1;
        }
        else if(a[j].se-a[i].se==ans&&a[i].se+1<l) l=a[i].se+1;
        i=j+1;
    }
    Write(l); putchar(' '); Write(ans);
}
int main()
{
    TL
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    solve();
}
/// JUST KEEP TRAINING





