#define nmnhat "tram"
#include <bits/stdc++.h>
using namespace std;
vector<int> f[100000+5];
long long a,b,v,s,t[1000005],d=1,x,res[1000005],k=0,l[1000005],ma=-999999999;
long long kq;
void dfs(int u)
{
    for(int i=0;i<f[u].size();i++)
    {
        if(t[f[u][i]]==0)
        {
            t[f[u][i]]=u;
            dfs(f[u][i]);
        }
        else if(t[u]!=f[u][i])
        {
            t[f[u][i]]=u;
            x=u;
            return;
        }
    }
}
void dfs1(int u)
{
    for(int i=0;i<f[u].size();i++)
    {
        if(l[f[u][i]]==0)
        {
            l[f[u][i]]=-1;
            kq++;
            if(ma<kq)ma=kq;
            dfs1(f[u][i]);
            kq--;
        }
    }
}
void ra()
{
    res[1]=x;
    while(t[x]!=res[1])
    {
        l[x]=-1;
        d++;
        res[d]=x;
        x=t[x];
    }
    d++;
    res[d]=x;
    l[x]=-1;
}
int main()
{
    freopen(nmnhat".inp","r",stdin);
    freopen(nmnhat".out","w",stdout);
    scanf("%lld\n",&v);
    for(int i=1;i<=v;i++)
    {
        scanf("%lld %lld",&a,&b);
        f[a].push_back(b);
        f[b].push_back(a);
    }
    s=1;
    t[1]=-1;
    dfs(1);
    ra();
    for(int i=d;i>=2;i--)
    {
        for(int j=0;j<f[res[i]].size();j++)
        {
            if(l[f[res[i]][j]]!=-1)f[v+1].push_back(f[res[i]][j]);
//            cout<<f[i][j]<<' ';
        }
//        cout<<endl;
    }
    dfs1(v+1);
    cout<<ma;
//    for(int i=0;i<f[v+1].size();i++)
//        cout<<' '<<f[v+1][i];
}
