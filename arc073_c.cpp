#include<bits/stdc++.h>

using namespace std;

#define task "arc073_c"
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

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,b,a) for(int i=(b);i>=(a);--i)
#define REP(i,a,b) for(int i=(a);i<(b);++i)

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;

const int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const int dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1000000007; /// 998244353
const int base=311;

const int N=2e5+5;

pii a[N];
int n;

ll calc1()
{
    sort(a+1,a+n+1);

    /// rmax=max, bmin=min, rmin greater, bmax smaller

    ll ans=(a[n].fi-a[1].fi);

    int mx=0, mn=2e9;
    for(int i=1;i<=n;++i)
    {
        mx=max(mx,a[i].se);
        mn=min(mn,a[i].se);
    }
    ans*=(mx-mn);
    return ans;
}
ll calc2()
{

}
void biot()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].fi>>a[i].se;
        if(a[i].fi<a[i].se) swap(a[i].fi,a[i].se);
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
    biot();
    return 0;
}

