#include<bits/stdc++.h>
using namespace std;
#define task "calcnum"
#define lb lower_bound
#define ub upper_bound
#define alll(v) (v).begin(),(v).end()
#define szz(v) (v).size()
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i,b,a) for (int i = (b), _a = (a); i >= _a; --i)
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;

const int MOD=1000000007; /// 998244353
const int base=311; /// for hash actually
const int N=1e5+5;

ll f[20][164][1500][2];
ll solve(vector<int> dig,int pos, ll x, ll y, int tight)
{
//    cout<<pos<<' '<<x<<' '<<y<<endl;
    if(pos==szz(dig))
    {
        if(__gcd(x,y)==1) return 1;
        return 0;
    }
    ll &res=f[pos][x][y][tight];
    if(res!=-1) return res;
    int lim=9;
    if(tight) lim=dig[pos];
    res=0;
    for(int i=0;i<=lim;++i)
    {
        int t;
        if(dig[pos]==i) t=tight;
        else t=0;
        res+=solve(dig,pos+1,x+i,y+i*i,t);
    }
    return res;
}
ll calc(ll r)
{
    vector<int> dig;
    dig.clear();
    while(r>0)
    {
        dig.pb(r%10);
        r/=10;
    }
    reverse(alll(dig));
    return solve(dig,0,0,0,1);
}
void solved()
{
    ll l,r;
    memset(f,-1,sizeof(f));
    cin>>l>>r;
    cout<<calc(r)-calc(l-1)<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t;
    cin>>t;
    while(t--) solved();
}
