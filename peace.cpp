#include<bits/stdc++.h>

using namespace std;

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
int h[N],anc[N][30];
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
int dist(int u, int v)
{
    return h[u]+h[v]-2*h[lca(u,v)];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("peace.inp","r",stdin);
    freopen("peace.out","w",stdout);

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

    while(m--)
    {
        int r,x,y;
        vector<int> R;
        R.clear();
        read(r); read(x); read(y);
        int r1=lca(x,y), r2=lca(r,x), r3=lca(r,y);
        R.push_back(lca(x,y));
        R.push_back(lca(r,x));
        R.push_back(lca(r,y));
        R.push_back(r);
        R.push_back(x);
        R.push_back(y);
        int mn=2e9;
        for(int i=0;i<R.size();++i)
        {
            int u=R[i];
            mn=min(mn,dist(u,r)+dist(u,x)+dist(u,y));
        }

        for(int i=0;i<R.size();++i)
        {
            int u=R[i];
            if(dist(u,r)+dist(u,x)+dist(u,y)==mn)
            {
                write(R[i]);
                putchar('\n');
                break;
            }
        }
    }

}







