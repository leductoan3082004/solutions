#include<bits/stdc++.h>

using namespace std;

#define task "MULTQ3"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;
const int N = 100005;
struct three
{
    int mod0,mod1,mod2,num;
};
three st[N * 4];
int n,m;
three sum(three a, three b, three c)
{
    return {a.mod0 + b.mod0 ,a.mod1 + b.mod1 , a.mod2 + b.mod2, c.num};
}
void build(int i, int l, int r)
{
    if (l == r) {
        st[i].mod0 = 1;
        return;
    }
    build(i * 2,l, (l +r ) / 2);
    build(i * 2 + 1, (l + r ) / 2 + 1, r);
    st[i] = sum(st[2 * i],st[i * 2 + 1], st[i]);
}
void down(int i, int l, int r)
{
    if (st[i].num == 0) return;
    int t = st[i].num;
    t %= 3;
    st[2 * i].num += st[i].num;
    st[2 * i + 1].num += st[i].num;

    st[2 * i].num %= 3;
    st[2 * i + 1].num %= 3;

    int d = 1;
    while (d <= t) {
        int mod0 = st[i * 2].mod0;
        int mod1 = st[i * 2].mod1;
        int mod2 = st[i * 2].mod2;
        st[i * 2].mod0 = mod2;
        st[i * 2].mod1 = mod0;
        st[i * 2].mod2 = mod1;
        ++ d;
    }
    d = 1;
    while (d <= t) {
        int mod0 = st[i * 2 + 1].mod0;
        int mod1 = st[i * 2 + 1].mod1;
        int mod2 = st[i * 2 + 1].mod2;
        st[i * 2 + 1].mod0 = mod2;
        st[i * 2 + 1].mod1 = mod0;
        st[i * 2 + 1].mod2 = mod1;
        ++ d;
    }
    st[i].num = 0;
}
void update(int i, int l, int r , int u, int v)
{
    if (u > r || v < l ) return;
    if (u <= l && r <= v) {
        st[i].num ++;
        int mod0 = st[i].mod0;
        int mod1 = st[i].mod1;
        int mod2 = st[i].mod2;
        st[i].mod0 = mod2;
        st[i].mod1 = mod0;
        st[i].mod2 = mod1;
        return;
    }
    down(i,l,r);
    update(i * 2, l , (l + r) / 2, u ,v );
    update(i * 2 + 1, (l + r) / 2 + 1, r , u, v);
    st[i] = sum(st[2 * i], st[2 * i + 1],st[i]);
}
three get(int i, int l, int r, int u, int v)
{
    if (u > r || v < l ) return {0,0,0,0};
    if (u <= l && r <= v) return st[i];
    down(i,l,r);
    return sum(get(i*2,l,(l + r)/2,u,v),get(i*2+1,(l + r)/2+1,r,u,v),st[1]);
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n >> m;
    build(1,1,n);
    while (m --) {
        int t , u , v; cin >> t >> u >> v;
        u ++ ; v ++;
        if (t == 0) {
            update(1,1,n,u,v);
        }
        else {
            cout << get(1,1,n,u,v).mod0 << '\n';
        }
    }
//        }
}










