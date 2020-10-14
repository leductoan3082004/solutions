#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "C11BC2"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int N = 1e4 + 5;

int h[N],w[N],q[N][20],n,m;
vector<pii> a[N];
void dfs(int u, int pre)
{
    for (int i = 0; i < a[u].size(); ++i) {
        int v = a[u][i].first;
        int we = a[u][i].second;
        if (v == pre) continue;
        h[v] = h[u] + 1;
        w[v] = w[u] + we;
        q[v][0] = u;
        dfs(v, u);
    }
}
void create()
{
    dfs(1,1);
    for (int j = 1; j <= log2(n); ++j) {
        for (int i = 1; i <= n; ++i) q[i][j] = q[q[i][j - 1]][j - 1];
    }
}
int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u,v);
    int k = log2(h[u]);

    for (int i = k; i >= 1; --i)
    if (h[u] - (1 << i) >= h[v]) u = q[u][i];
    if (u == v) return u;

    for (int i = k; i >= 1; --i) {
        if (q[u][i] && q[u][i] != q[v][i]) {
            u = q[u][i];
            v = q[v][i];
        }
    }
    return q[u][0];
}
int main()
{
    TL
//    freopen(task".inp","r",stdin);
//    freopen(task".out","w",stdout);

    cin >> n >> m;
    for (int u = 2; u <= n; ++u) {
        int v , w;
        cin >> v >> w;
        --w;
        a[u].push_back(make_pair(v,w));
        a[v].push_back(make_pair(u,w));
    }
    create();

    while (m--) {
        int u ,v;
        cin >> u >> v;
        if (w[u] + w[v] - 2 * w[LCA(u,v)] == 0) cout << "NO\n";
        else cout << "YES\n";
    }
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.










