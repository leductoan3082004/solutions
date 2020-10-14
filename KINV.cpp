#include<bits/stdc++.h>

using namespace std;

#define task "KINV"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

const int N = 1e4 + 5;
const int K = 12;
const int mod = 1e9 + 7;

int st[K][4 * N] , a[N] , n , k;
int ans = 0;

void update(int t , int i, int l, int r, int p, int val)
{
    if (p > r || p < l) return;
    if (l == r) {
        st[t][i] = (st[t][i] + val) % mod;
        return;
    }
    update(t,i*2,l,(l+r)/2,p,val);
    update(t,i*2+1,(l+r)/2+1,r,p,val);
    st[t][i] = (st[t][2*i] + st[t][2*i+1]) % mod;
}
int get(int t, int i, int l, int r, int u ,int v)
{
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return st[t][i];
    return (get(t,i*2,l,(l+r)/2,u,v) + get(t,i*2+1,(l+r)/2+1,r,u,v)) % mod;
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            int cur = get(j - 1,1,1,n,a[i] + 1,n) + 1;
            update(j,1,1,n,a[i],cur);
        }
    }
    ans = get(k,1,1,n,1,n);
    cout << ans ;
}










