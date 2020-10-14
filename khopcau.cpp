#include<bits/stdc++.h>
using namespace std;
#define task "khopcau"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define pf pop_front
#define mp make_pair
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(),(v).end()

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a,b) for(int i=(a);i<(b);++i)

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
const int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const int dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1000000007; /// 998244353
const int base=311;
const int N=1e5+5;

int n,m;
vector<int> ans,dsk[N];
vector<pii> br;
int low[N],num[N],cnt,ok[N],khop,cau;

void dfs(int u, int pre)
{
    int child=0;
    num[u]=low[u]=++cnt;
    for(int v:dsk[u])
    {
        if(v==pre) continue;
        if(num[v]) low[u]=min(low[u],low[v]);
        else
        {
            ++child;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(num[u]<low[v]) br.pb(mp(u,v));
            if(u==pre)
            {
                if(child>=2) ok[u]=1;
            }
            else if(num[u]<=low[v]){
                ok[u]=1;
            }
        }
    }
}
void biot()
{
    cin>>n>>m;
    FOR(i,1,m)
    {
        int u,v; cin>>u>>v;
        dsk[u].pb(v);dsk[v].pb(u);
    }
    FOR(i,1,n) if(!num[i]) dfs(i,i);
    FOR(i,1,n) if(ok[i]) ans.pb(i);
    cout<<zs(ans)<<' '<<zs(br)<<'\n';
    for(int i:ans) cout<<i<<'\n';
    for(pii i:br) cout<<i.fi<<' '<<i.se<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    biot();
    return 0;
}
