#include<bits/stdc++.h>
using namespace std;
#define task "vo17xxx"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define mp make_pair
#define rep(i,a,b) for (ll i = (a), _b = (b); i <= _b; ++i)
#define repd(i,b,a) for (ll i = (b), _a = (a); i >= _a; --i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> ii;

const ll base=331;
const ll  mod=1e9+3;

ll n,k;
ll pw[100005];
vector<ll> h[55];
string s[55];

ll get(ll id, ll i, ll j)
{
    return (h[id][j]-(ll)h[id][i-1]*pw[j-i+1]+(ll)mod*mod)%mod;
}

bool check(ll len)
{
    vector<ii> q;
    q.clear();
    for(ll i=1;i<=n;++i)
    {
        ll sz=s[i].size()-1;
        if(len>sz) continue;
        for(ll j=1;j<=sz-len+1;++j)
        {
            q.push_back({get(i,j,j+len-1),i});
//            if(get(i,j,j+len-1)==330879313) cout<<i<<' '<<s[i].substr(j,len)<<endl;
        }
    }
    ///330879313
    sort(q.begin(),q.end());
    q.resize(unique(q.begin(),q.end())-q.begin());
    ll d=0;
    for(ll i=0;i<q.size();++i)
    {
        ++d;
//        if(d==7) cout<<q[i].fi<<endl;
        if(i+1==(ll)q.size()||q[i].fi!=q[i+1].fi)
        {
            if(d>=k) return true;
            d=0;
        }
    }
    return false;
}
void solve()
{
    cin>>n>>k;
    pw[0]=1;
    for(ll i=1;i<=100000;++i) pw[i]=(ll)pw[i-1]*base%mod;
    ll lim=0;
    for(ll i=1;i<=n;++i)
    {
        cin>>s[i];
        lim=max(lim,(ll)s[i].size());
        h[i].resize((ll)s[i].size()+5);
        s[i]=' '+s[i];
        for(ll j=1;j<s[i].size();++j)
        {
            ///ok
            h[i][j]=(h[i][j-1]*base+s[i][j]-'A'+1)%mod;
        }
    }
//    cout<<check(812)<<endl;
    ll ans=0, l=0, r=lim;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        if(check(mid)) ans=mid, l=mid+1;
        else r=mid-1;
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
    solve();
}





