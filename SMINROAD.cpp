#include<bits/stdc++.h>

using namespace std;

#define task "SMINROAD"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

const int N = 1e5 + 5;
struct two
{
    int u , v, w;
};
int n , m , w[N] , par[N];
ll ans = 0;
vector<two> e;

int root(int u)
{
    if (par[u] < 0) return u;
    else return par[u] = root(par[u]);
}
void Union(two k)
{
    int u = k.u, v = k.v, w = k.w;
    u = root(u);
    v = root(v);
    if (u == v) return;
    if (par[u] > par[v]) swap(u,v);
    ans += 1LL * w * par[u] * par[v];
    par[u] += par[v];
    par[v] = u;
    return;
}

bool cmp(two a, two b)
{
    return a.w > b.w;
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) par[i] = -1;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1; i <= m; ++i) {
        int u , v;
        cin >> u >> v;
        e.push_back({u,v,min(w[u],w[v])});
    }
    sort(e.begin(),e.end(),cmp);

    for (auto i : e) {
//        cout << i.u << ' ' << i.v << ' ' << i.w << endl;
        Union(i);
    }
    cout << 2LL * ans;

    return 0;
}










