#include<bits/stdc++.h>
using namespace std;
#define task "dhexp"
#define lwb lower_bound
#define upb upper_bound
#define ar array
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

int n,k,a[100005];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+2,a+n+1,greater<int>());
    ll ans=a[1];
    for(int i=2;i<=k+1;++i) ans+=a[i];
    for(int i=k+2;i<=n;++i) ans-=a[i];
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





