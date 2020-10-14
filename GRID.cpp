#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "GRID"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<ll,ll> pii;

const ll mod=1e9+7;

ll pw(ll n, ll k)
{
    if (k==1) return n;
    if (k==0) return 1;
    ll t=pw(n,k/2);
    if (k&1) return (((t*t)%mod)*n)%mod;
    else return (t*t)%mod;
}
void solve()
{
    ll n;
    cin >> n;
    n%=mod;
    n=n*(n+1)/2 % mod;
    cout << ((ll)2048*pw(n,2))%mod;
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.











