#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "LEM4"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int oo = 2e9;
const ll inf = 1e15;
const int N = 1e4 + 5;

struct three
{
    int L , R, cen;
};

three st[4 * N] ;
int lazy[4 * N] , n , m;

void down(int i, int l, int r)
{
    if (lazy[i] == -1) return;
    int val = lazy[i];
    int mid = (l + r) >> 1;
    st[i << 1].L = st[i << 1].R = st[i << 1].cen = val * (mid - l + 1);
    st[i << 1 | 1].L = st[i << 1 | 1].R = st[i << 1 | 1].cen = val * (r - mid);
    lazy[i << 1] = lazy[i << 1 | 1] = val;
    lazy[i] = -1;
}

three mer(int l, int r, three a, three b)
{
    three ans;
    int mid = (l + r) >> 1;
    if (a.L == mid - l + 1) ans.L = a.L + b.L;
    else ans.L = a.L;
    if (b.R == r - mid) ans.R = a.R + b.R;
    else ans.R = b.R;
    ans.cen = max(max(a.cen,b.cen) , a.R + b.L);
    return ans;
}
void update(int i, int l, int r, int u, int v, int val)
{
    if (u > r || v < l ) return ;
    if (u <= l && r <= v) {
        st[i].L = st[i].R = st[i].cen = val * (r - l + 1);
        lazy[i] = val;
        return;
    }
    down(i, l, r);
    int mid = (l + r) >> 1;
    update(i << 1, l, mid, u, v, val);
    update(i << 1 | 1, mid + 1, r, u, v, val);
    st[i] = mer(l, r, st[i << 1] ,st[i << 1 | 1]);
}

three get(int i, int l, int r, int u, int v)
{
    if (u > r || v < l) return {0,0,0};
    if (u <= l && r <= v) return st[i];
    down(i, l, r);
    int mid = (l + r) >> 1;
    three L = get(i << 1, l ,mid, u, v);
    three R = get(i << 1 | 1,mid + 1, r, u, v);
    return mer(l,r,L,R);
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= 4 * n; ++i) lazy[i] = -1;
    update(1,1,n,1,n,1);
    while (m--) {
        int t , u , v;
        cin >> t;
        if (t == 1) {
            cin >> u >> v;
            update(1,1,n,u,v,1);
        }
        if (t == 2) {
            cin >> u >> v;
            update(1,1,n,u,v,0);
        }

        if (t == 3) cout << get(1, 1, n, 1,n).cen << '\n';
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










