#include<bits/stdc++.h>

using namespace std;

#define task "ATM"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

const int N = 4e5 + 5;

int num[N],low[N],cnt,n,m,p[N],dem,d[N],dd[N];
ll s[N],dp[N];
vector<int> a[N],dsk[N];
stack<int> S;

void dfs(int u)
{
    num[u] = low[u] = ++cnt;
    S.push(u);
    for (int v : a[u]) {
        if (dd[v]) continue;
        if (!num[v]) {
            dfs(v);
            low[u] = min(low[v],low[u]);
        }
        else low[u] = min(low[u],num[v]);
    }
    if (num[u] == low[u]) {
        int v;
        ++dem;
        do {
            v = S.top();
            dd[v] = 1;
            S.pop();
            d[v] = dem;
        } while (v != u);
    }
}
void DFS(int u)
{
    dp[u] = s[u];
    dd[u] = 1;
    for (int v : dsk[u]) {
        if (!dd[v]) {
            DFS(v);
            dp[u] = max(dp[u],dp[v] + s[u]);
        }
        else dp[u] = max(dp[u],dp[v] + s[u]);
    }
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    for (int i = 1; i <= m; ++i) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i) {
        if (num[i]) continue;
        dfs(i);
    }
    for (int i = 1; i <= n; ++i) s[d[i]] += p[i];
    for (int i = 1; i <= n; ++i) dd[i] = 0;
//    cout << dem << endl;
//    for (int i = 1; i <= n; ++i) cout << d[i] << ' ';
//    cout << endl;
    for (int u = 1; u <= n; ++u) {
        for (int v : a[u]) {
            if (d[u] == d[v]) continue;
            dsk[d[u]].push_back(d[v]);
        }
    }
    for (int i = 1; i <= dem; ++i) {
        if (!dd[i]) DFS(i);
    }

    cout << *max_element(dp + 1, dp + dem + 1);
}










