#include<bits/stdc++.h>
using namespace std;
struct two
{
    int u,v,w;
};
const int N=1e4+5;
int par[N],n,m;
vector<two>a;
int root(int u)
{
    if (par[u]<0) return u;
    else return par[u]=root(par[u]);
}

void Union(int a, int b)
{
    int u=root(a);
    int v=root(b);
    if (u==v) return ;
    if (par[u]>par[v]) swap(u,v);
    par[u]+=par[v];
    par[v]=u;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("C11BC2.inp","r",stdin);
    freopen("C11BC2.out","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=n; i++) par[i]=-1;
    for (int i=2; i<=n; i++){
        int u,w;
        cin>>u>>w;
        a.push_back({i,u,w});
    }
    for (int i=0; i<a.size(); i++){
        if (a[i].w==2) continue;
        Union(a[i].u,a[i].v);
    }
    while(m--){
        int u,v;
        cin>>u>>v;
        if (root(u)==root(v)) cout<<"NO";
        else cout<<"YES";
        cout<<endl;
    }
}
