#include<bits/stdc++.h>

using namespace std;

#define task "LOTTERY"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;
map<int,int> dd;
const int N = 1e5+5;
int n,a,b,g[N];
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n >> a >> b;
    for (ll i = 1; i <= n; ++i) {
        cin >> g[i];
        dd[g[i]] ++ ;
    }
    ll Mintime = 1e9;
    ll Lucky = 1e9;
    for (ll i = 1; i <= n; ++i) {
        if (Mintime > dd[g[i]]) {
            Lucky = g[i];
            Mintime = dd[g[i]];
        }
        else if (Mintime == dd[g[i]]) {
            Lucky = min(Lucky,1LL * g[i]);
        }
    }
    vector<ll> q;
    for (ll i = 1; i <= n; ++i) {
        if (g[i] == Lucky) {
            q.push_back(i);
        }
    }
    ll k = (1LL * a * n) - (1LL * q.size() * b);
    cout << k << ' ' << q.size() << '\n';
    for (int i = 0; i < q.size(); ++i) cout << q[i] << ' ';

}










