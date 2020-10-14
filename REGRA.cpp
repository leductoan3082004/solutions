#include<bits/stdc++.h>

using namespace std;

#define task "REGRA"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

const int N = 1e5 + 5;
int h[N],dd[N],n,m,q,ans[N];
vector<int> a[N];
void update(int u, int dis, int val, int k)
{
    h[u] = 0;
    deque<int> q;
    q.push_back(u);
    dd[u] = k;
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        dd[u] = k;
        ans[u] = max(ans[u],val);

        for (int v : a[u]) {
            if (dd[v] == k) continue;
            h[v] = h[u] + 1;
            if (h[v] > dis) continue;
            dd[v] = k;
            q.push_back(v);
        }
    }
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n >> m >> q;

    while (m--) {
        int u, v ;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 1; i <= q; ++i) {
        int u , d , x;
        cin >> u >> d >> x;
        update(u , d, x , i);
    }

    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}










