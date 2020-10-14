/*https://bom.to/nxtvde2k1m4l*/
#include<bits/stdc++.h>
using namespace std;
#define task "UPGRADE"
#define debug cout << '\n';
typedef long long ll;
typedef pair<ll,int> ii;
const int N = 1e5 + 5;
const ll inf = 1e15;
struct three
{
    int u,v;
    ll w;
};
vector<ll> f1,fn;
int n,m,num[N],low[N],ind,ans;
vector < ii > a[N];
vector < three > edges;
vector <int > dsk[N];
void init()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
void dijkstra(vector<ll> &f, int s)
{
    for (int i = 1; i <= n; i ++) f[i] = inf;

    f[s] = 0;

    priority_queue < ii , vector < ii > , greater <ii > > q;

    q.push({f[s],s});

    while (!q.empty()) {
        int u = q.top().second;
        ll len = q.top().first;

        q.pop();

        if (f[u] < len) continue;

        for (int i = 0; i < a[u].size(); i ++) {
            int v = a[u][i].first;
            ll w = a[u][i].second;

            if (f[v] > f[u] + w) {
                f[v] = f[u] + w;
                q.push({f[v],v});
            }
        }
    }
}
void dfs(int u, int pre)
{
    num[u] = low[u] = ++ind;

    for (int i = 0; i < dsk[u].size(); i ++) {
        int v = dsk[u][i];
        if (v == pre) continue;
        if (!num[v]) {
            dfs(v,u);
            low[u] = min (low[u],low[v]);
        }
        else low[u] = min(num[v],low[u]);

        if (num[u] < low[v]) ans ++ ;
    }
}

int main()
{
    init();
    scanf("%d%d",&n,&m);
    f1 = vector <ll> (n+5);
    fn = vector <ll> (n+5);
    for (int i = 1; i <= m; i ++)  {
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }

    dijkstra(f1,1);
    dijkstra(fn,n);

    for (int u=1; u<=n; u++)
    for (int i=0; i<a[u].size(); i++) {
        int v = a[u][i].first;
        ll w = a[u][i].second;
        if (u < v && (f1[u]+fn[v]+w == f1[n] || fn[u] + f1[v] + w == f1[n])){
            dsk[u].push_back(v);
            dsk[v].push_back(u);
        }
    }

    dfs(1,1);

    printf("%d",ans);
}

