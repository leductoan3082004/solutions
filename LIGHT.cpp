//Truong Minh Tri
#include <bits/stdc++.h>
#define FOR(i, x, y) for(int i = x; i <= y; ++i)
#define FORN(i, x, y) for(int i = x; i >= y; --i)
#define Task "LIGHT"
#define maxn 100005
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mp make_pair
#define pb push_pack
using namespace std;
int n, m, k;
vector<int> a[maxn], BIT[maxn];
struct data{
    int u, v, x, y;
} luu[maxn];
long long res = INT_MAX, st[maxn], b[maxn];
void Calc()
{
    int temp = 0;
    FOR(i, 1, n) b[i] = a[1][i];
    FOR(i, 1, k)
        FOR(j, luu[i].v, luu[i].y) (b[j] += st[i]) %= 3;
    int maxx = *max_element(b+1, b+n+1);
    int minn = *min_element(b+1, b+n+1);
    if(maxx==minn && maxx != 0) res = min(res, accumulate(st+1, st+k+1, 0ll));
}
void Try(int pos)
{
    if(pos==k+1)
    {
        Calc();
        return;
    }
    FOR(i, 0, 2)
    {
        st[pos] = i;
        Try(pos+1);
    }
}
bool comp(data x, data y)
{
    if(x.u != y.u) return x.u < y.u;
    if(x.v != y.v) return x.v < y.v;
    if(x.x != y.x) return x.x < y.x;
    return x.y < y.y;
}
long long Get(int x, int y)
{
    long long sum = 0;
    for(int i = x; i; i -= i&(-i))
        for(int j = y; j; j -= j&(-j)) sum += BIT[i][j];
    return sum;
}
void Up(int x, int y, int val)
{
    for(int i = x; i <= m; i +=i&(-i))
        for(int j = y; j <= n; j +=j&(-j)) BIT[i][j] += val;
}
void Update(int x, int y, int u, int v, int val)
{
    Up(x, y, val);
    Up(u+1, y, -val);
    Up(x, v+1, - val);
    Up(u+1, v+1, val);
}
void Full()
{
    sort(luu+ 1, luu + k + 1, comp);
    FOR(color, 1, 2)
    {
        long long temp = 0;
        FOR(i, 0, m)
            FOR(j, 0, n) BIT[i][j] = 0;
        FOR(i, 1, k)
        {
            int u = luu[i].u;
            int v = luu[i].v;
            int x = (a[u][v] + Get(u, v)) % 3;
            int add = (color + 3 - x) % 3;
            temp += add;
            Update(u, v, luu[i].x, luu[i].y, add);
        }
        bool ok = 1;
        FOR(i, 1, m)
        {
            if(!ok) break;
            FOR(j, 1, n)
            {
                int x = (a[i][j] +  Get(i, j)) % 3;
                if(x != color)
                {
                    ok = 0;
                    break;
                }
            }
        }
        if(ok) res = min(res, temp);
    }
    if(res==INT_MAX) cout << -1;
    else cout << res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> m >> n >> k;
    FOR(i, 0, m) a[i].resize(n+10), BIT[i].resize(n+10);
    FOR(i, 1, m)
        FOR(j, 1, n) cin >> a[i][j];
    FOR(i, 1, k) cin >> luu[i].u >> luu[i].v >> luu[i].x >> luu[i].y;
    if(m==1 && n <= 10)
    {

        Try(1);
        if(res==INT_MAX) cout << -1;
        else cout << res;
    }
    else
        Full();
}
