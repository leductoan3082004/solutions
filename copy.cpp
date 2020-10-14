#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "copy"
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
typedef pair<int,int> pii;

const int mxn=1000005;
int n,w,a[mxn];
void solve()
{
    Read(n); Read(w);
    for(int i=1;i<=n;++i) Read(a[i]);
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;++i) {
        w-=a[i];
        if(w<0) break;
        ++ans;
    }
    Write(ans);
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





