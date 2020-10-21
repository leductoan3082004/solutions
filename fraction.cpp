#include<bits/stdc++.h>

using namespace std;

#define task "fraction"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(),(v).end()
#define endl '\n'

typedef long double ld;
typedef long long ll;
typedef pair<ll,ll> pii;

const int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const int dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};

const ll mod=1000000007; /// 998244353
const int base=311;

struct segtree
{
    int n;
    vector<int> st;

    segtree(int _n)
    {
        n=_n;
        st.assign(4*n+5,0);
    }
    void upd(int i, int l, int r, int p, int val)
    {
        if(l==r)
        {
            st[i]=max(st[i],val);
            return;
        }
        int mid=(l+r)>>1;
        if(p<=mid) upd(i<<1,l,mid,p,val);
        else upd(i<<1|1,mid+1,r,p,val);
        st[i]=max(st[i<<1],st[i<<1|1]);
    }
    int get(int i, int l, int r, int u, int v)
    {
        if(u>r||v<l) return 0;
        if(u<=l&&r<=v) return st[i];
        int mid=(l+r)>>1;
        return max(get(i<<1,l,mid,u,v),get(i<<1|1,mid+1,r,u,v));
    }
};

template <typename T>
inline void read(T& x)
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
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

const int N=1e5+5;

int n,w,b[N],c[N];
pii a[N];
vector<pii> s;
map<pii,int> M;

bool cmp(pii a, pii b)
{
    return a.fi*b.se<b.fi*a.se;
}
void solve()
{
    read(n); read(w);
    for(int i=1;i<=n;++i)
    {
        read(a[i].fi); read(a[i].se);
        s.pb(a[i]);
        s.pb({a[i].se,a[i].fi});
    }
    s.pb(mp(-1,1));
    sort(ALL(s),cmp);
    s.resize(unique(ALL(s))-s.begin());


    for(int i=0;i<zs(s);++i) M[s[i]]=i;

    for(int i=1;i<=n;++i)
    {
        b[i]=M[a[i]];
        c[i]=M[mp(a[i].se,a[i].fi)];
    }
    segtree st(zs(s)+5);

    for(int i=1;i<=n;++i)
    {
        int val0=st.get(1,0,zs(s),0,b[i]-1);
        int val1=st.get(1,0,zs(s),0,c[i]-1);
        st.upd(1,0,zs(s),b[i],val0+1);
        if(w) st.upd(1,0,zs(s),c[i],val1+1);
    }
    cout<<st.st[1];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    solve();
}






