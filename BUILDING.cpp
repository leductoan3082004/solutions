#include<bits/stdc++.h>
using namespace std;

#define task "building"
#define fi first
#define se second
#define fore(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define ford(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)

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
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int mxn=500005;

vector<int> a,b;
int n,m;

void solve()
{
    read(n);
    a.push_back(2e9);
    b.push_back(-1);
    for(int i=1;i<=n;++i)
    {
        int x; read(x);
        if(x<0) b.push_back(-x);
        else a.push_back(x);
    }
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end());
    n=a.size()-1;
    m=b.size()-1;

//    for(int i=1;i<=n;++i) cout<<a[i]<<' ';
//    cout<<endl;
//    for(int j=1;j<=m;++j) cout<<b[j]<<' ';
//    cout<<endl;
    int i=1, j=m, ans1=1, ans2=1;
    int turn=1;
    while(i<=n&&j>=1)
    {
        if(!turn)
        {
            while(j>=1&&b[j]>a[i]) --j;
            if(i<=n&&j>=1&&b[j]<=a[i]) ++ans1;
            turn=1;
        }
        else
        {
            while(i<=n&&a[i]>b[j]) ++i;
            if(i<=n&&j>=1&&a[i]<=b[j]) ++ans1;
            turn=0;
        }
//        cout<<i<<' '<<j<<'\n';
    }
    turn=0;
    i=1; j=m;
    while(i<=n&&j>=1)
    {
        if(!turn)
        {
            while(j>=1&&b[j]>a[i]) --j;
            if(i<=n&&j>=1&&b[j]<=a[i]) ++ans2;
            turn=1;
        }
        else
        {
            while(i<=n&&a[i]>b[j]) ++i;
            if(i<=n&&j>=1&&a[i]<=b[j]) ++ans2;
            turn=0;
        }
//        cout<<i<<' '<<j<<'\n';
    }
    cout<<max(ans1,ans2);
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


