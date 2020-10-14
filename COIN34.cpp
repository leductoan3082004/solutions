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
#define task "COIN34"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<ll,int> pii;

const int N = 35;
int a[N] ;
ll div1[N] , div2[N];
vector<pii> q1,q2;

void init(ll *d, vector<pii> &q)
{
    for (int mask = 1; mask < (1 << 17); ++mask) {
        int dem = 0;
        ll sum = 0;
        for (int i = 0; i < 17; ++i) {
            if ((mask >> i) & 1) {
                ++dem;
                sum += d[i];
            }
        }
        q.push_back(make_pair(sum,dem));
    }
}

void solve(int x)
{
    int ans = -1;
    for (auto i : q1) {
        ll sum = x - i.first;
        int k = upper_bound(q2.begin(),q2.end() , make_pair(sum,INT_MAX)) - q2.begin() - 1;
        if (k < 0) continue;
        if (q2[k].first == sum) ans = max(ans,i.second + q2[k].second);
    }
    cout << ans << '\n';
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    int t; Read(t);
    a[1] = 2; a[2] = 3; a[3] = 5;
    for (int i = 4; i <= 34; ++i)
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];

    for (int i = 1; i <= 17; ++i) div1[i - 1] = a[i];

    for (int i = 18; i <= 34; ++i) div2[i - 18] = a[i];
    q1.push_back({0,0});
    q2.push_back({0,0});
    init(div1,q1);
    init(div2,q2);
    sort(q2.begin(),q2.end());
    for (int test = 1; test <= t; ++test) {
        int x;
        Read(x);
        cout << "Case #" << test << ": ";
        solve(x);
    }
}










