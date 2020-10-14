#include<bits/stdc++.h>
using namespace std;
#define task "graph"
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
const int N=200005;
vector<int> a[N],nen;
int dd[N],n,s,t,m;
struct two
{
        int u,v;
};
vector<two> e;
void dfs(int u)
{
    dd[u]=1;
    for(int v:a[u])
    {
        if(!dd[v]) dfs(v);
    }
}
bool kt(int k)
{
//    cout<<nen.size()<<endl;
    for(int i=1;i<=nen.size();++i)
    {
        a[i].clear();
        dd[i]=0;
    }
    for(int i=1;i<=k;++i)
    {
        int u=lower_bound(nen.begin(),nen.end(),e[i].u)-nen.begin()+1;
        int v=lower_bound(nen.begin(),nen.end(),e[i].v)-nen.begin()+1;
//        cout<<u<<' '<<v<<endl;
        a[u].push_back(v);
    }
    int ps=lower_bound(ALL(nen),s)-nen.begin()+1;
    dfs(ps);
    int pt=lower_bound(ALL(nen),t)-nen.begin()+1;
    if(dd[pt]) return true;
    else return false;
}

void solve()
{
    read(m); read(s); read(t);
//    cout<<m<<endl;
    nen.push_back(s);
    nen.push_back(t);
    e.resize(m+5);
    for(int i=1;i<=m;++i)
    {
        read(e[i].u); read(e[i].v);
        nen.push_back(e[i].u);
        nen.push_back(e[i].v);
    }
    sort(nen.begin(),nen.end());
    nen.resize(unique(nen.begin(),nen.end())-nen.begin());
    int l=0, r=m,ans=0;
//    cout<<kt(45398)<<endl;
//    FOR(i,1,m) cout<<kt(i)<<" ";
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(kt(mid))
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



