#include<bits/stdc++.h>
using namespace std;
#define task "flowgrow"
#define lwb lower_bound
#define upb upper_bound
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> p2i;
typedef pair<ll,p2i> p3i;
typedef pair<p2i,p2i> p4i;

const ll mod=2370823708;
ll pw(ll n, ll k)
{
    if(k==1) return n;
    if(k==0) return 1;
    ll t=pw(n,k/2);
    if(k&1) return ((t%mod)*(t%mod))*(n%mod)%mod;
    else return ((t%mod)*(t%mod))%mod;
}
ll C(ll n, ll k)
{
    ll tu=1,mau=1;
    for(ll i=1;i<=n;++i) tu*=i;
    for(ll i=1;i<=k;++i) mau*=i;
    for(ll i=1;i<=n-k;++i) mau*=i;
    return tu/mau;
}
void solve()
{
    ll n=-1,m=-1,k=-1;
    cin>>m>>n>>k;
    if(m==-1||n==-1||k==-1) exit(0);
    if(k>7)
    {
        cout<<0<<'\n';
        return;
    }
    ///f[i] = i^n - sum(f[1]->f[i-1])
    vector<ll> dp(8,0);
    ll pre=1;
    dp[1]=1;
    for(ll i=2;i<=7;++i)
    {
        dp[i]=pw(i,n);
        for(ll j=1;j<i;++j)
        dp[i]=(dp[i]-(dp[j]%mod)*C(i,j)%mod+mod*mod)%mod;
    }
//    cout<<dp[2]<<endl;
    ll ans=0;
    for(ll i=k;i<=7;++i)
    {
        ans=(ans+(dp[i]%mod)*C(7,i)%mod)%mod;
//        cout<<dp[i]<<'\n';
    }
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
    while(1)solve();
}






