#include<bits/stdc++.h>
using namespace std;
#define task "lcaquery"
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
const int N=100005;
int n,m;
int h[N],anc[N][30],st[4*N];
vector<int> a[N];

void dfs(int u, int pre)
{
    for(int v:a[u])
    {
        if(v==pre) continue;
        anc[v][0]=u;
        h[v]=h[u]+1;
        dfs(v,u);
    }
}
void initlca()
{
    for(int j=1;j<=log2(n);++j)
        for(int i=1;i<=n;++i)
            anc[i][j]=anc[anc[i][j-1]][j-1];
}
int lca(int u, int v)
{
    if(u==0|v==0) return u+v;
    if(h[u]<h[v]) swap(u,v);
    int k=log2(h[u]);
    for(int i=k;i>=0;--i)
        if(h[u]-(1<<i)>=h[v]) u=anc[u][i];
    if(u==v) return u;
    for(int i=k;i>=0;--i)
        if(anc[u][i]&&anc[u][i]!=anc[v][i])
            u=anc[u][i], v=anc[v][i];
    return anc[u][0];
}
void build(int i, int l, int r)
{
    if(l==r)
    {
        st[i]=l;
        return;
    }
    int mid=(l+r)>>1;
    build(i<<1,l,mid);
    build(i<<1|1,mid+1,r);
    st[i]=lca(st[i<<1],st[i<<1|1]);
}
int get(int i, int l, int r, int u, int v)
{
    if(u>r||v<l) return 0;
    if(u<=l&&r<=v) return st[i];
    int mid=(l+r)>>1;
    return lca(get(i<<1,l,mid,u,v),get(i<<1|1,mid+1,r,u,v));
}
void solve()
{
    read(n); read(m);
    for(int i=1;i<n;++i)
    {
        int u,v;
        read(u); read(v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,1);
    initlca();
    build(1,1,n);

    for(int i=1;i<=m;++i)
    {
        int l,r;
        read(l); read(r);
        write(get(1,1,n,l,r));
        putchar('\n');
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
    solve();
}



