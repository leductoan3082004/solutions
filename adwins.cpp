#include<bits/stdc++.h>

using namespace std;

#define task "adwins"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define pf pop_front
#define mp make_pair
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(),(v).end()

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a,b) for(int i=(a);i<(b);++i)

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;

const int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const int dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1000000007; /// 998244353
const int base=311;

const int N=2e5+5;

struct points
{
    int x,y,u,v;
};
struct three
{
    int x,y,t;
};
points a[N];
int n,st[8*N];
vector<int> storex,storey;

int cmp1(three a, three b)
{
    return (a.x<b.x||(a.x==b.x&&a.t<b.t));
}
int cmp2(three a, three b)
{
    return (a.y<b.y||(a.y==b.y&&a.t<b.t));
}
ll solve1()
{
    vector<three> point;
    point.clear();
    for(int i=1;i<=n;++i)
    {
        point.pb({a[i].x,a[i].y,-1});
        point.pb({a[i].u,a[i].v,1});
    }
    sort(ALL(point),cmp1);
    int low=0;
    ll ans=0;
    for(int i=0;i<zs(point);++i)
    {
        int j=i;
        while(j<zs(point)-1&&point[i].x==point[j+1].x) ++j;
        for(int k=i;k<=j;++k)
        {
            if(point[k].t==-1) ans+=low;
        }
        for(int k=i;k<=j;++k)
        {
            if(point[k].t==1) low++;
        }
        i=j;
    }
    return ans;
}
ll solve2()
{
    vector<three> point;
    point.clear();
    for(int i=1;i<=n;++i)
    {
        point.pb({a[i].x,a[i].y,-1});
        point.pb({a[i].u,a[i].v,1});
    }
    sort(ALL(point),cmp2);
    int low=0;
    ll ans=0;
    for(int i=0;i<zs(point);++i)
    {
        int j=i;
        while(j<zs(point)-1&&point[i].y==point[j+1].y) ++j;
        for(int k=i;k<=j;++k)
        {
            if(point[k].t==-1) ans+=low;
        }
        for(int k=i;k<=j;++k)
        {
            if(point[k].t==1) low++;
        }
        i=j;
    }
    return ans;
}
void upd(int p, int i=1, int l=0, int r=zs(storey)+5)
{
    if(l==r) {st[i]++; return;}
    int mid=(l+r)>>1;
    if(p<=mid) upd(p,i<<1,l,mid);
    else upd(p,i<<1|1,mid+1,r);
    st[i]=st[i<<1]+st[i<<1|1];
}
int get(int u, int v, int i=1, int l=0, int r=zs(storey)+5)
{
    if(u>r||v<l) return 0;
    if(u<=l&&r<=v) return st[i];
    int mid=(l+r)>>1;
    return get(u,v,i<<1,l,mid)+get(u,v,i<<1|1,mid+1,r);
}
ll solve3()
{
    vector<three> point;
    point.clear();
    for(int i=0;i<=4*zs(storey);++i)
    {
        st[i]=0;
    }
    for(int i=1;i<=n;++i)
    {
        point.pb({a[i].x,a[i].y,-1});
        point.pb({a[i].u,a[i].v,1});
    }
    sort(ALL(point),cmp1);
    ll ans=0;
    for(int i=0;i<zs(point);++i)
    {
        int x=point[i].x, y=point[i].y;
        if(point[i].t==-1) ans+=get(0,point[i].y-1);
        else upd(point[i].y);
    }
    point.clear();
    for(int i=1;i<=n;++i)
    {
        point.pb({a[i].x,a[i].v,-1});
        point.pb({a[i].u,a[i].y,1});
    }
    sort(ALL(point),cmp1);
    for(int i=0;i<=4*zs(storey);++i)
    {
        st[i]=0;
    }
    for(int i=0;i<zs(point);++i)
    {
        int x=point[i].x, y=point[i].y;
        if(point[i].t==-1) ans+=get(point[i].y+1,zs(storey));
        else upd(point[i].y);
    }
    return ans;
}
int check(points a, points b)
{
    if(a.x>b.u&&a.y>b.v) return true;
    if(b.x>a.u&&b.y>a.v) return true;
    return false;
}
void biot()
{
    cin>>n;
    storex.clear();
    storey.clear();
    for(int i=1;i<=n;++i)
    {
        int x,y,u,v; cin>>x>>y>>u>>v;
        assert(x<=u); assert(y<=v);
        a[i]={x,y,u,v};
        storex.pb(x);
        storey.pb(y);
        storex.pb(u);
        storey.pb(v);
    }
    storex.pb(-1);
    storey.pb(-1);
    sort(ALL(storex));
    sort(ALL(storey));
    storex.resize(unique(ALL(storex))-storex.begin());
    storey.resize(unique(ALL(storey))-storey.begin());
    for(int i=1;i<=n;++i)
    {
        int x=lb(ALL(storex),a[i].x)-storex.begin();
        int y=lb(ALL(storey),a[i].y)-storey.begin();
        int u=lb(ALL(storex),a[i].u)-storex.begin();
        int v=lb(ALL(storey),a[i].v)-storey.begin();
        a[i]={x,y,u,v};
    }
    ll ans=(ll)n*(n-1)/2;
    ans=ans-solve1()-solve2()+solve3();

    cout<<ans<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t=1;
    cin>>t;
    while(t--) biot();
    return 0;
}






