#include<bits/stdc++.h>
using namespace std;
#define task "atcodedr"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define pf pop_front
#define mp make_pair
#define zs(v) (ll)(v).size()
#define BIT(x, i) (((x) >> (i)) & 1)
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(),(v).end()
#define FOR(i,a,b) for(ll i=(a);i<=(b);++i)
#define FORD(i,b,a) for(ll i=(b);i>=(a);--i)
#define REP(i,a,b) for(ll i=(a);i<(b);++i)
typedef long double ld;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const ll dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1000000007; /// 998244353
const ll base=311;
const ll N=100+5;

ll n,w,a[N],b[N];
vector<ll> v[5];
void biot()
{
    cin>>n>>w;
    for(ll i=1;i<=n;++i) cin>>a[i]>>b[i];
    for(ll i=0;i<=3;++i) v[i].pb(0);
    for(ll i=1;i<=n;++i) v[a[i]-a[1]].pb(b[i]);
    for(ll i=0;i<=3;++i) sort(v[i].begin()+1,v[i].end(),greater<ll>());
    for(ll i=0;i<=3;++i)
    {
        for(ll j=1;j<zs(v[i]);++j) v[i][j]+=v[i][j-1];
    }
    ll ans=0;
    for(ll i=0;i<zs(v[0]);++i)
    {
        for(ll j=0;j<zs(v[1]);++j)
        {
            for(ll k=0;k<zs(v[2]);++k)
            {
                for(ll c=0;c<zs(v[3]);++c)
                {
                    ll t=a[1];
                    ll sumw=i*t+j*(t+1)+k*(t+2)+c*(t+3);
                    if(sumw>w) continue;
                    ans=max(ans,v[0][i]+v[1][j]+v[2][k]+v[3][c]);
                }
            }
        }
    }
    cout<<ans;
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












