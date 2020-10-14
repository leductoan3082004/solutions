#include<bits/stdc++.h>

using namespace std;

#define task "LIGHTS"

typedef long long ll ;
typedef pair<ll,ll> ii;
map<ii,ll> M;
vector<ll> a[40];
ll Pow[40];
ll getbit(ll n, ll i)
{
    return (n >> i) & 1;
}
void turn(ll &mask, int i)
{
    mask ^=  (1LL << i);
}
void process(vector<ll> q, vector<ii> &qu)
{
    ll sz = q.size();
    for (ll    mask = 0; mask < (1 << sz); ++mask) {
        ll    new_mask = 0, d = 0;
        for (ll    i = 0; i < sz; ++i) {
            if (getbit(mask,i) == 1) {
                d++;
                turn(new_mask , q[i]);
                for (int v : a[q[i]]) {
                    turn(new_mask,v);
                }
            }
        }
        qu.push_back(make_pair(d,new_mask));
    }
}
bool cmp(ii a, ii b)
{
    if (a.second != b.second) return a.second < b.second;
    return a.first > b.first;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    ll    n,m;

    cin >> n >> m;
    n --;
    for (ll    i = 0; i < m; ++i) {
        ll    u ,v ;
        cin >> u >> v;
        u -- , v --;
        if (M[make_pair(u,v)]) continue;
        M[make_pair(u,v)] = 1;
        M[make_pair(v,u)] = 1;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vector<ll   > f,g;
    vector<ii> q1,q2;
    for (ll i = 0; i < n/2; ++i) f.push_back(i);
    for (ll i = n/2; i <= n; ++i) g.push_back(i);
    process(f,q1);
    process(g,q2);
    sort(q1.begin(),q1.end(),cmp);
    sort(q2.begin(),q2.end(),cmp);
    ll   ans = 1e9;
    for (ll i = 0; i < q1.size(); ++i) {
        ll  remain = (1LL << (n + 1)) - 1 - q1[i].second;
        ll   l = 0, r = q2.size() - 1, k = -1;
        while (l <= r) {
            ll  mid = (l + r) / 2;
            if (q2[mid].second == remain) k = mid;
            if (q2[mid].second <= remain) {
                l = mid + 1;
            }
            else r = mid - 1;
        }
        if ( k != -1 ) {
            ans = min(ans,q2[k].first + q1[i].first);
        }
    }
    cout << ans;
}








