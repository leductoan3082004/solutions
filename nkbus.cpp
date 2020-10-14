#include<bits/stdc++.h>
using namespace std;
#define task "nkbus"
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

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<ll> f(n+5),a;
    for(int i=1;i<=n;++i)
    {
        int time;
        cin>>time;
        f[i+1]+=time+f[i];
        int num; cin>>num;
        for(int j=1;j<=num;++j)
        {
            int x; cin>>x;
            a.push_back(max(0LL,x-f[i]));
        }
    }
//    for(int i=1;i<=n;++i) cout<<f[i]<<' ';
//    cout<<endl;
    sort(a.begin(),a.end());
    ll ans=f[n+1];
    if(a.size()<=m) ans+=a.back();
    else ans+=a[m-1];
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




