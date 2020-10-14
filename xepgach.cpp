#include<bits/stdc++.h>
using namespace std;
#define task "xepgach"
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
typedef pair<ll,ll> pii;

int n;
vector<pii> a;
ll ans=0;

bool cmp(pii a, pii b)
{
    if(a.fi!=b.fi) return a.fi>b.fi;
    else return a.se<b.se;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int x,y;
        cin>>x>>y;
        a.push_back({x,y});
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=1;i<=n;++i)
    {
        ll x=a[i-1].fi, y=a[i-1].se;
        ans+=x*(i-1)+y*(n-i);
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





