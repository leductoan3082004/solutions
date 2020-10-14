#include<bits/stdc++.h>
using namespace std;
#define task "ndivi"
#define fi first
#define se second
#define fore_(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define fore(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define ford(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

void solve()
{
    ll n,k,ans=0;
    cin>>n>>k;
    ll l=1,r=1e18;
    while(l<=r)
    {
        ll mid=(l+r)>>1LL;
        if(mid-mid/n>=k)
        {
            r=mid-1;
            ans=mid;
        }
        else l=mid+1;
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
    while(t--)
    solve();
}


