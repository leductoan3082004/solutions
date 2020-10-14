#include<bits/stdc++.h>

using namespace std;

#define task "wcalc"
#define fi first
#define se second

typedef long long ll;
typedef pair<ll,ll> ii;

void solve()
{
    ll b,n,ans=0;
    cin>>b>>n;
    /// b*m^2-2*b*n*m+a*n*n=0.
    for(ll a=0;a<b;++a) {
        ll delta=b*b-b*a; ///n*n*b(b-a)
        ll candelta=sqrt(delta);
//        if(a==9) cout<<delta<<'\n';
        if(candelta*candelta==delta) {
            candelta*=n;
            ll m1=(b*n-candelta)%b;
            ll m2=(b*n+candelta)%b;
            if(m1==0&&b*n-candelta>0) ++ans;
            if(delta!=0&&m2==0&&b*n+candelta>0) ++ans;
        }
//        cout<<a<<' '<<ans<<'\n';
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






