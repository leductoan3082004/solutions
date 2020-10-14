#include<bits/stdc++.h>

using namespace std;

#define task "ccay"
#define fi first
#define se second
#define fore(i,a,b) for(int i=(int)a;i<=(int)b;++i)
#define ford(i,a,b) for(int i=(int)a;i>=(int)b;--i)

typedef long long ll;
typedef pair<int,int> pii;

struct three
{
    char c;
    int u,v;
};
vector<three> qry;
const int mxn=20005;
int n,q,par[mxn],dd[mxn],anc[mxn];

int root(int u)
{
    if(par[u]<0) return u;
    else return par[u]=root(par[u]);
}
void dsu(int u, int v)
{
    u=root(u); v=root(v);
    if(u==v) return;
    if(par[u]>par[v]) swap(u,v);
    par[u]+=par[v];
    par[v]=u;
}
void ILYPTV()
{
    cin>>n>>q;
    for(int i=1;i<=n;++i)
    {
        cin>>anc[i];
        if(anc[i]==0) anc[i]=i;
    }
    fill(par+1,par+n+1,-1);
    fill(dd+1,dd+n+1,0);
    qry.clear();
    for(int i=1;i<=q;++i)
    {
        char c;
        cin>>c;
        if(c=='Q')
        {
            int u,v;
            cin>>u>>v;
            qry.push_back({c,u,v});
        }
        else
        {
            int u;
            cin>>u;
            ++dd[u];
            qry.push_back({c,u,0});
        }
    }

    reverse(qry.begin(),qry.end());

    vector<string> ans;
    for(int i=1;i<=n;++i)
        if(!dd[i]) dsu(i,anc[i]);
    for(auto i:qry)
    {
        char c=i.c;
        int u=i.u, v=i.v;
        if(c=='Q')
        {
            if(root(u)==root(v)) ans.push_back("YES");
            else ans.push_back("NO");
        }
        else
        {
            --dd[u];
            if(dd[u]==0) dsu(u,anc[u]);
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();++i) cout<<ans[i]<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t;
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        cout<<"Case #"<<i<<":\n";
        ILYPTV();
    }
}






