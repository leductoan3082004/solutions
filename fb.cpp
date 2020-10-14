#include<bits/stdc++.h>
using namespace std;
#define task "fb"
#define lwb lower_bound
#define upb upper_bound
#define ar array
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ALL(v) (v).begin(), (v).end()
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

map<int,ll> dp;

int n;
pii a[800005];
void solve()
{
    dp.clear();
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].fi>>a[i].se;
    }
    ll ans=0;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)
    {
        ll tmp1=0;
        ll l1=a[i].fi, r1=a[i].fi+a[i].se;
        if(dp.count(l1)) tmp1=dp[l1]+r1-l1;
        else tmp1=r1-l1;
        ll l2=a[i].fi-a[i].se, r2=a[i].fi,tmp2=0;
        if(dp.count(l2)) tmp2=dp[l2]+r2-l2;
        else tmp2=r2-l2;
        dp[r1]=max(dp[r1],tmp1);
        dp[r2]=max(dp[r2],tmp2);
        ans=max({ans,dp[r1],dp[r2]});
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
    int t;
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }

}




