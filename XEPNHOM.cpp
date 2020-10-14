#include<bits/stdc++.h>

using namespace std;

#define task "XEPNHOM"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;
const int N = 1e5 + 5;
struct two
{
    ll val;
    int cnt;
};
int n , k , R;
int a[N];
vector<int> s;
two st[4 * N];
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
void update(int i, int l, int r, int p, int val)
{
    if (p < l || p > r) return;
    if (l == r)
    {
        st[i].val += val;
        st[i].cnt ++;
        return;
    }
    update(i*2,l,(l+r)/2,p,val);
    update(i*2+1,(l+r)/2+1,r,p,val);
    st[i].val = st[2 * i].val + st[2 * i + 1].val;
    st[i].cnt = st[2 * i].cnt + st[2 * i + 1].cnt;
}
two get(int i, int l, int r, int u, int v)
{
    if (u > r || v < l) return {0,0};
    if (u <= l && r <= v) return st[i];
    two L = get(i*2,l,(l+r)/2,u,v);
    two R = get(i*2 + 1,(l+r)/2+1,r,u,v);
    return {L.val + R.val, L.cnt + R.cnt};
}
bool check(ll group, int i)
{
    int p = upper_bound(s.begin(),s.end(),group) - s.begin() - 1;
    two L = get(1,1,n,1,p);
    ll num = group * k;
    ll tmp = L.val + 1LL * (i - L.cnt) * group;
    return (tmp >= num);
}
void solve()
{
    Read(n); Read(k); Read(R);
    s.clear();
    s.push_back(-1e15);
    for (int i = 1; i <= 4 * n; ++i) st[i] = {0,0};
    for (int i = 1; i <= n; ++i)
    {
        Read(a[i]);
        s.push_back(a[i]);
    }
    sort(s.begin() , s.end());
    s.resize(unique(s.begin(),s.end()) - s.begin());
    ll sum = 0;
    for (int i = 1; i <= R; ++i)
    {
        int p = lower_bound(s.begin(),s.end(),a[i]) - s.begin();
        update(1,1,n,p,a[i]);
        sum += a[i];
    }

    for (int i = R + 1; i <= n; ++i)
    {
        sum += a[i];
        ll l = 0, r = sum / k, ans = 0;
        int p = lower_bound(s.begin(),s.end(),a[i]) - s.begin();
        update(1,1,n,p,a[i]);
        while (l <= r)
        {
            ll mid = (l + r) >> 1;
            if (check(mid,i))
            {
                l = mid + 1;
                ans = mid;
            }
            else r = mid - 1;
        }
        Write(ans); putchar(' ');
    }
    putchar('\n');
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    int t;
    Read(t);
    while (t--) solve();
}










