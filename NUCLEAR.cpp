#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "nuclear"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

template <typename T>
inline void Read(T& x)
{
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' | c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void Write(T x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}
typedef long long ll;
typedef pair<int,int> pii;

const int mxn = 2e5 + 5;

int n, ax, ay, bx, by, q, st[4 * mxn], f[4 * mxn], g[4 * mxn], ans[4 * mxn];
pii a[mxn], dis[mxn], qry[mxn];
vector<pii> sw[mxn];

void update(int i, int l, int r, int p)
{
    if (p > r || p < l) return ;
    if (l == r) {
        ++st[i];
        return;
    }
    int mid = (l + r) >> 1;
    update(i << 1, l, mid, p);
    update(i << 1 | 1, mid + 1, r, p);
    st[i] = st[i << 1] + st[i << 1 | 1];
}
int get(int i, int l, int r, int u, int v)
{
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return st[i];
    int mid = (l + r) >> 1;
    return get(i << 1, l, mid, u, v) + get(i << 1 | 1, mid + 1, r, u, v);
}
ll SQR(int k)
{
    return 1LL * k * k;
}
int dist(int x1, int y1, int x2, int y2)
{
    return (int)ceil(1.00 * sqrt(SQR(y2 - y1) + SQR(x2 - x1)));
}
void solve()
{
    Read(n);
    for (int i = 1; i <= n; ++i) {
        Read(a[i].first); Read(a[i].second);
    }
    Read(ax); Read(ay); Read(bx); Read(by); Read(q);
//    cin >> ax >> ay >> bx >> by >> q;

    for (int i = 1; i <= n; ++i) {
        dis[i] = make_pair(dist(a[i].first,a[i].second,ax,ay),
                           dist(a[i].first,a[i].second,bx,by));
        ++f[dis[i].first];
        ++g[dis[i].second];
        sw[dis[i].first].push_back(make_pair(dis[i].second,0));
    }

    for (int i = 1; i <= 2e5; ++i) {
        f[i] += f[i - 1];
        g[i] += g[i - 1];
    }
    for (int i = 1; i <= q; ++i) {
        Read(qry[i].first); Read(qry[i].second);
//        cin >> qry[i].first >> qry[i].second;
        sw[qry[i].first].push_back(make_pair(qry[i].second,i));
    }
    for (int i = 0; i <= 2e5; ++i) {
        sort(sw[i].begin(),sw[i].end());
        for (int j = 0; j < sw[i].size(); ++j) {
            if (sw[i][j].second == 0) update(1,0,mxn - 1,sw[i][j].first);
            else ans[sw[i][j].second] = get(1,0,mxn - 1,0,sw[i][j].first);
        }
    }

    for (int i = 1; i <= q; ++i) {
        Write(f[qry[i].first] + g[qry[i].second] - ans[i]);
        putchar('\n');
    }
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.











