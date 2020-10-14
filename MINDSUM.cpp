#include<bits/stdc++.h>

using namespace std;

#define task "MINDSUM"

typedef pair<int,int> ii;
typedef long long ll;

const int N = 1e5 + 1;
vector< pair<int,int> > a[N + 1];
int f[N + 1];
void dijkstra(int s)
{
    priority_queue<ii,vector<ii>,greater<ii> > q;
    for (int i = 0; i <= N; ++i) f[i] =  1e9;
    f[s] = 0;
    q.push(make_pair(0,s));
    while (!q.empty()) {
        int u = q.top().second;
        int len = q.top().first;
        q.pop();
        if (f[u] < len) continue;

        for (int i = 0; i < a[u].size(); ++i) {
            int v = a[u][i].first;
            int w = a[u][i].second;
            if (f[v] > f[u] + w) {
                f[v] = f[u] + w;
                q.push(make_pair(f[v],v));
            }
        }
    }
    cout << f[0];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    int k ;
    cin >> k;

    for (int i = 1; i <= 9; ++i) {
        a[N].push_back(make_pair(i,i));
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j <= 9; ++j) {
            a[i].push_back(make_pair((i * 10 + j) % k, j));
        }
    }
    dijkstra(N);
}







