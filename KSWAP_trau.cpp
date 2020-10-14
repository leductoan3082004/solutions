#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
typedef long long ll;
ll a[N];
ll n,k;
struct two
{
    ll val;
    int pos;
};
two st[4*N];
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("KSWAP.inp","r",stdin);
    freopen("KSWAP.ans","w",stdout);
}
void up(int i)
{
    two L = st[2*i];
    two R = st[2*i+1];
    if (L.val >= R.val) st[i] = L;
    else st[i] = R;
}
void update(int i, int l, int r, int vt, ll val)
{
    if (vt < l ||  vt > r ) return;
    if (l == r) {
        st[i] = {val,vt};
        return;
    }
    update(i * 2,l, (l+r)/2,vt,val);
    update(i*2+1,(l+r)/2+1,r,vt,val);
    up(i);
}
two get(int i, int l, int r, int u, int v)
{
    if ( u > r || v < l) return {0,0};
    if (u <= l && r <= v) return st[i];
    two L = get(2*i,l,(l+r)/2,u,v);
    two R = get(2*i+1,(l+r)/2+1,r,u,v);
    if (L.val >= R.val) return L;
    else return R;
}
void nhap()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        update(1,1,n,i,a[i]);
    }
}
void xuli1()
{
    for (int i=1; i<=n; i++) {
        int Max = -1,pos=i;
        int v = min( i+k, n);
        for (int j=i; j<=v ; j++) {
            if (Max < a[j]) Max = a[j] , pos = j;
        }
        k -= (pos-i);
        for (int x=pos; x > i; x-- ) swap(a[x],a[x-1]);
        if (k == 0 ) break;
    }
    for (int i=1; i<=n; i++) cout << a[i] << ' ';
}
void xuli2()
{
    for (int i=1; i<=n; i++) {
        int u = i;
        int v = min (i + k, n);
        two t = get(1,1,n,u,v);
        int j = t.pos;
        k -= (j-i);
        for (int x=j; x > i; x-- ) swap(a[x],a[x-1]);
        for (int x=i; x<=j; x++) update(1,1,n,x,a[x]);
        if (k == 0 ) break;
    }
    for (int i=1; i<=n; i++) cout << a[i] << ' ';
}
int main()
{
    init();
    nhap();
    xuli2();
}
