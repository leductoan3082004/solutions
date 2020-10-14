#include<bits/stdc++.h>

using namespace std;

#define task "increasing_subsequence_ii"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int st[4 * N],a[N],n;
vector<int> s;
void update(int i, int l, int r, int p, int val)
{
    if (p > r || p < l) return ;
    if (l == r)
    {
        st[i] = (st[i] + val) % mod;
        return;
    }
    update(i*2,l,(l+r)/2,p,val);
    update(i*2+1,(l+r)/2+1,r,p,val);
    st[i] = (st[2 * i] + st[2 * i + 1]) % mod;
}
int get(int i, int l, int r, int u, int v)
{
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return st[i];
    return (get(i*2,l,(l+r)/2,u,v) + get(i*2+1,(l+r)/2+1,r,u,v)) % mod;
}
int main()
{
    TL
//    freopen(task".inp","r",stdin);
//    freopen(task".out","w",stdout);

    cin >> n;
    s.push_back(-2e9);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        s.push_back(a[i]);
    }
    sort(s.begin(),s.end());
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int k = lower_bound(s.begin(),s.end(),a[i]) - s.begin();
        int t = get(1,1,n,1,k - 1) + 1;
        ans = (ans + t) % mod;
        update(1,1,n,k,t);
    }
    cout << ans;
}










