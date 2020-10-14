#include<bits/stdc++.h>

using namespace std;

#define task "NKINV"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

const int N = 60005;
int n,a[N],st[4 * N];
ll ans = 0;
void update(int i, int l, int r, int k)
{
    if (k < l || k > r) return;
    if (l == r) {
        st[i] ++;
        return;
    }
    update(i*2,l,(l+r)/2,k);
    update(i*2+1,(l+r)/2+1,r,k);
    st[i] = st[2 * i] + st[2 * i + 1];
}
ll get(int i, int l, int r, int u, int v)
{
    if (u > r || v < l) return 0 ;
    if (u <= l && r <= v) return st[i];
    return get(i*2,l,(l+r)/2,u,v) + get(i*2+1,(l+r)/2+1,r,u,v);
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n ;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        int k = get(1,1,N   ,a[i] + 1,60000);
        ans += k;
        update(1,1,N,a[i]);
    }

    cout << ans;
}










