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
    if(u==0||v==0) return u+v;
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
