#include<bits/stdc++.h>
using namespace std;
#define task "alpha"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl '\n'
#define rep(i,a,b) for (ll i = (a), _b = (b); i <= _b; ++i)
#define repd(i,b,a) for (ll i = (b), _a = (a); i >= _a; --i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;
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
const int N=1e6;
vector<int> q;
int f[N+5],mod,tc,pos[N+5];
pair<ll,int> st[4*80000];

ll pw(ll n, ll k)
{
    if(k==1) return n;
    if(k==0) return 1;
    ll t=pw(n,k/2);
    if(k&1) return t*t%mod*n%mod;
    else return t*t%mod;
}
void sieve()
{
    f[1]=1;
    f[0]=1;
    for(int i=2;i<=1000;++i)
        if(!f[i])
            for(int j=i*i;j<=1000000;j+=i)
                f[j]=1;
    for(int i=2;i<=1000000;++i)
        if(!f[i])
        {
            pos[i]=q.size();
            q.pb(i);
        }
}
vector<ii> factor(int a)
{
    ///for(int i=2;i<=sqrt(a);++i)
    vector<ii> ans; ans.clear();
    for(int i:q)
    {
        if(i*i>a) break;
        if(a%i==0)
        {
            int cnt=0;
            while(a%i==0) a/=i,++cnt;
            ans.pb({i,cnt});
        }
    }
    if(a>1) ans.pb({a,1});
    return ans;
}
void upd(int i, int l, int r, int p, int val)
{
    if(l==r)
    {
        st[i].fi=q[l];
        st[i].se+=val;
        return;
    }
    int mid=(l+r)>>1;
    if(p<=mid) upd(i<<1,l,mid,p,val);
    else upd(i<<1|1,mid+1,r,p,val);
    st[i].se=__gcd(st[i<<1].se,st[i<<1|1].se);
    if(st[i].se==0)
    {
        st[i].fi=1;
        return;
    }
    st[i].fi=((ll)pw(st[i<<1|1].fi,st[i<<1|1].se/st[i].se)*pw(st[i<<1].fi,st[i<<1].se/st[i].se))%mod;
}
void solve()
{
    sieve();
    read(mod); read(tc);
//    cout<<q.size()<<endl;
//    cout<<pos[2]<<endl;
    while(tc--)
    {
        int t; read(t);
        if(t==1||t==2)
        {
            int a,b;
            read(a); read(b);
            b=(t==1?b:-b);
            vector<ii> p=factor(a);
            for(ii i:p) upd(1,0,q.size()-1,pos[i.fi],i.se*b);
        }
        else
        {
//            cout<<st[1].fi<<endl;
            if(st[1].se==0)
            {
                write(1); putchar(' '); write(1);
            }
            else
            {
                write(st[1].fi); putchar(' '); write(st[1].se);
            }
            putchar('\n');
        }
    }
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






