#include<bits/stdc++.h>
using namespace std;

#define task "doigach"
#define fi first
#define se second
#define fore(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);++i)
#define ford(i,a,b) for(ll i=(ll)(a);i>=(ll)(b);--i)

typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> pii;

ll n,m,a[15],f[15][10005];
void solve()
{
    cin>>n>>m;
    for(ll i=1;i<=n;++i)
        cin>>a[i];

    for(int i=0;i<=n;++i)
        for(int j=0;j<=m;++j)
            f[i][j]=2e9;
    f[0][0]=0;
    for(ll i=1;i<=n;++i)
    {
        for(ll k=0;k<=m;++k)
        {
            for(ll j=1;j<=100;++j)
        {
//                f[i][k]=min(f[i][k],f[i-1][k]);
                if(k-j*j>=0)
                    f[i][k]=min(f[i][k],f[i-1][k-j*j]+(a[i]-j)*(a[i]-j));
        }
        }
    }
    cout<<(f[n][m]==2e9?-1:f[n][m]);
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


