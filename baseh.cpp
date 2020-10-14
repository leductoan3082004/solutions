#include<bits/stdc++.h>
using namespace std;
#define task "baseh"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define mp make_pair
#define ALL(v) (v).begin(), (v).end()
#define dembit __builtin_popcountll
#define rep(i,a,b) for (ll i = (a), _b = (b); i <= _b; ++i)
#define repd(i,b,a) for (ll i = (b), _a = (a); i >= _a; --i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> ii;
map<ll,ll> a;
ll calc(ll k, ll h)
{
//    cout<<k<<endl;
    if(a.count(k)) return a[k];

    if(k&1) return a[k]=h*calc((k-1)/2,h)+1;
    else return a[k]=h*calc(k/2,h);
}
void solve()
{
    ll k,h;
    a[1]=1;
    cin>>k>>h;
    ll ans=calc(k,h);
//    cout<<ans<<endl;
    while(ans>1)
    {
        cout<<ans/h;
        ans%=h;
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






