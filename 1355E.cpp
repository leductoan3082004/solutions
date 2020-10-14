#include<bits/stdc++.h>

using namespace std;

#define task "1355E"
#define fi first
#define se second
#define fore(i,a,b) for(ll i=(ll)a;i<=(ll)b;++i)
#define ford(i,a,b) for(ll i=(ll)a;i>=(ll)b;--i)

typedef long long ll;
typedef pair<ll,ll> pii;

const ll mxn=100005;
ll n,A,R,M,a[mxn];


ll calc(ll h)
{
    ll thua=0, thieu=0;
    for(ll i=1;i<=n;++i)
    {
        if(a[i]>h) thua+=a[i]-h;
        if(a[i]<h) thieu+=h-a[i];
    }

    ll res=0;
    if(M<=A+R)
    {
        ll k=min(thua,thieu);
        res+=k*M;
        thua-=k;
        thieu-=k;
    }
    res+=thua*R+thieu*A;
    return res;
}
void solve()
{
    cin>>n>>A>>R>>M;
    for(ll i=1;i<=n;++i)
        cin>>a[i];

//    for(ll i=0;i<=15;++i) cout<<calc(i)<<' ';
    ll l=0, r=(ll)2e9,ans=0;
    while(l<=r)
    {
        ll mid=(l+r)/2LL;
//        cout<<mid<<'\n';
        if(calc(mid)>calc(mid-1))
        {
            r=mid-1;
            ans=mid-1;
        }
        else l=mid+1;
    }
//    cout<<'\n';
//    cout<<ans<<'\n';
    cout<<calc(ans);
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






