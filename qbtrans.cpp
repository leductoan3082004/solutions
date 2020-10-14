#include<bits/stdc++.h>
using namespace std;
#define task "qbtrans"
#define BIT(x, i) (((x) >> (i)) & 1)
#define lb lower_bound
#define ub upper_bound
#define lla(v) (v).begin(),(v).end()
#define zs(v) (v).size()
#define fi first
#define se second
#define pb push_back
#define ar array
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1000000007; /// 998244353
const int base=311;
const int N=1e5+5;

struct trip
{
    int u,v;
    ld w;
};
vector<trip> e;
int n,m;
int check(ld val)
{
    vector<ld> f(n+1,1e9);
    vector<trip> ed;
    ed.clear();
    for(int i=0;i<m;++i) ed.pb({e[i].u,e[i].v,(ld)e[i].w-val});
    for(int i=1;i<n;++i)
    for(int j=0;j<m;++j)
    {
        int u=ed[j].u,v=ed[j].v;
        ld w=ed[j].w;
        f[v]=min(f[v],f[u]+w);
    }
    for(int j=0;j<m;++j)
    {
        int u=ed[j].u,v=ed[j].v;
        ld w=ed[j].w;
        if(f[v]>f[u]+w) return 0;
    }
    return 1;
}
void solved()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int u,v,c;
        cin>>u>>v>>c;
        e.pb({u,v,(ld)c});
    }
    ld l=0, r=1e10-1, ans=-1;
    /// sum/num=val
    /// sum-val*num==0
    /// num1<num -> sum-val*num1>=0 --->
//    cout<<check(1.00)<<endl;
    for(int i=1;i<=60;++i)
    {
        ld mid=(l+r)/2.00;
        if(check(mid)) l=mid,ans=mid;
        else r=mid;
    }
    if(ans>1e9) cout<<-1;
    else cout<<fixed<<setprecision(2)<<ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    solved();
}
