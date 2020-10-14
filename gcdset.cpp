#include<bits/stdc++.h>

using namespace std;

#define task "gcdset"
#define fi first
#define se second

typedef long long ll;
typedef pair<ll,ll> pii;

ll n;
ll k,a[20005];

void ILYPTV()
{
    cin>>n>>k;
    for(ll i=1;i<=n;++i) cin>>a[i];
    ll gcd=0;
    for(ll i=1;i<=n;++i)
        if(a[i]%k==0)
        {
            gcd=__gcd(gcd,a[i]);
        }
    cout<<(gcd==k?"YES":"NO");
    cout<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    ll t;
    cin>>t;
    while(t--) ILYPTV();
}






