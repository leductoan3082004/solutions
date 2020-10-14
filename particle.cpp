#include<bits/stdc++.h>
using namespace std;
#define task "particle"
#define lwb lower_bound
#define upb upper_bound
#define ar array
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ALL(v) (v).begin(), (v).end()
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

int n,q,par[100005],cnt,doi[100005];
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
    --cnt;
}
void solve()
{
    cin>>n>>q;
    cnt=n;
    for(int i=0;i<=n;++i) par[i]=-1;
    int r1=-1,r2=-1;
    while(q--)
    {
        char c;
        cin>>c;
        if(c=='R')
        {
            int u,v;
            cin>>u>>v;
            dsu(u,v);
        }
        else if(c=='A')
        {
            int u,v;
            cin>>u>>v;
            if(doi[root(u)]==0) doi[root(u)]=v;
            else dsu(doi[root(u)],v);
            if(doi[root(v)]==0) doi[root(v)]=u;
            else dsu(doi[root(v)],u);
            doi[root(u)]=root(v);
            doi[root(v)]=root(u);
        }
        else
        {
            int u,v;
            cin>>u>>v;
            u=root(u); v=root(v);
            if(u==v) cout<<"R\n";
            else if(root(doi[u])==v||root(doi[v])==u) cout<<"A\n";
            else cout<<"?\n";
        }
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





