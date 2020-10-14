#include<bits/stdc++.h>
using namespace std;
#define task "move12"
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOR_(i,a,b) for(int i=(a),_b=(b);i<_b;++i)
#define bug(x) cout<<#x<<'='<<x<<'\n'
#define pb push_back
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
const int N=10005;
int n,c[N],t[N];
bool check(int val)
{
    vector<pii> a;
    a.clear();
    for(int i=1;i<=n;++i) a.push_back({max(1,c[i]-val/t[i]),min(n,c[i]+val/t[i])});
    sort(a.begin(),a.end());
//    for(auto i:a) cout<<i.fi<<' '<<i.se<<endl;
    int j=0;
    priority_queue<int,vector<int>,greater<int>> q;
//    q.push(1);
//    q.push(2);
    while(!q.empty()) q.pop();
    for(int i=1;i<=n;++i)
    {
        while(j<n&&a[j].fi==i)
        {
            q.push(a[j].se);
            ++j;
        }
        while(!q.empty()&&q.top()<i) q.pop();
        if(q.empty()) return 0;
        q.pop();
    }
    return 1;
}
void solve()
{
    read(n);
    for(int i=1;i<=n;++i)
    {
        read(c[i]); read(t[i]);
    }

    int ans=0,l=0,r=1e9;
//    for(int i=1;i<=100;++i) cout<<check(i)<<endl;
//    cout<<check(18)<<endl;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            r=mid-1;
            ans=mid;
        }
        else l=mid+1;
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



