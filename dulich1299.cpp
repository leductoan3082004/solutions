#include<bits/stdc++.h>
using namespace std;

#define task "dulich1299"
#define fi first
#define se second
#define fore(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define ford(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)

typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int mxn=255;
int n,m,q,a[mxn][mxn],dd[mxn];
pii c[mxn];

void solve()
{
    cin>>n>>m>>q;

    for(int i=1;i<=n;++i) fill(a[i]+1,a[i]+n+1,1e9);

    for(int i=1;i<=n;++i)
    {
        cin>>c[i].fi;
        c[i].se=i;
        a[i][i]=0;
    }

    for(int i=1;i<=m;++i)
    {
        int u,v,c;
        cin>>u>>v>>c;
        a[u][v]=min(a[u][v],c);
        a[v][u]=min(a[v][u],c);
    }


    for(int k1=1;k1<=n;++k1)
    {
        int k=c[k1].se;
        dd[k]=1;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(dd[i]&&dd[j])
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]+c[k1].fi);

        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(dd[i]&&dd[j])
                    a[j][k]=min(a[j][k],a[j][i]+a[i][k]+c[k1].fi);

    }

    while(q--)
    {
        int u,v;
        cin>>u>>v;
        cout<<a[u][v]<<'\n';
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


