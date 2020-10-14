#include<bits/stdc++.h>
using namespace std;
#define task "DAGIAC"
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
const int N=4000+5;

struct three
{
    int x,y,pos;
};
int n, dd[N];
pii a[N];
vector<three> q;
int kc, st[N];

ll dt(three a, three b, three c)
{
    return (a.x-b.x)*(a.y+b.y)+(b.x-c.x)*(b.y+c.y)+(c.x-a.x)*(c.y+a.y);
}
bool cmp(three a, three b)
{
    return (dt(q[0],a,b)>=0);
}
void biot()
{
    cin>>n;
    FOR(i,1,n) cin>>a[i].fi>>a[i].se;

    int ans=0;
    int cnt=0;
    while(1)
    {
        ++cnt;
        if(cnt>n) break;
        int id=-1;
        q.clear();
        FOR(i,1,n) if(!dd[i]) q.pb({a[i].fi, a[i].se, i});
        REP(i,0,zs(q)) if(id==-1||(q[id].x>q[i].x)) id=i;
        if(zs(q)<=2) break;
        sort(q.begin()+1,q.end(),cmp);
        kc=0;
        REP(i,0,zs(q))
        {
            while(kc>=2&&dt(q[i],q[st[kc]],q[st[kc-1]])>0)
            {
                --kc;
            }
            st[++kc]=i;
        }
        FOR(i,1,kc) dd[q[st[i]].pos]=1;
        if(kc<=2) break;
        ++ans;
    }
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    biot();
    return 0;
}







