#include<bits/stdc++.h>
using namespace std;
#define task "colors"
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

const int mod=998244353;

void solve()
{
    int type, n, c;
    cin>>type>>n>>c;
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
    }
    ll ans=1;
    for(int i=1;i<n;++i) ans=(ans*(c-1))%mod;
    ans=(ans*c)%mod;
    if(n==1&&c==1) cout<<c;
    else if(c==1&&n>1) cout<<0;
    else cout<<ans;
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





