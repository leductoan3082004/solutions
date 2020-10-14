#include<bits/stdc++.h>

using namespace std;

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
#define task "C11SEQ"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int N = 1e5 + 5;
vector<ll> s;
ll f[N], st[12 * N];
int L , R , n;
void update(int i, int l, int r, int p)
{
    if (p > r || p < l) return ;
    if (l == r) {
        ++st[i];
        return;
    }
    int mid = (l + r) >> 1;
    update(i << 1, l ,mid,p);
    update(i << 1 | 1, mid + 1, r,  p);
    st[i] = st[i << 1] + st[i << 1 | 1];
}
ll get(int i, int l, int r, int u, int v)
{
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) {
        return st[i];
    }
    int mid = (l + r) >> 1;
    return get(i << 1, l, mid , u, v) + get(i << 1 | 1 , mid + 1,r,u,v);
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n >> L >> R;
    for (int i = 1; i <= n; ++i) {
        cin >> f[i];
        f[i] += f[i - 1];
        s.push_back(f[i]);
        s.push_back(L + f[i]);
        s.push_back(R + f[i]);
    }
    s.push_back(0);
    s.push_back(L);
    s.push_back(R);

    sort(s.begin(),s.end());
    s.resize(unique(s.begin(),s.end())- s.begin());
    int nst = s.size() + 5;
    ll ans = 0;
    for (int i = n; i >= 0; --i) {
        int u = lower_bound(s.begin(),s.end(),f[i] + L) - s.begin();
        int v = lower_bound(s.begin(),s.end(),f[i] + R) - s.begin();
        ans += get(1,1,nst,u,v);
//        cout << ans << endl;
        int k = lower_bound(s.begin(),s.end(),f[i]) - s.begin();
        update(1,1,nst,k);
    }
    cout << ans;
}










