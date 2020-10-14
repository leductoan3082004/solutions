#include<bits/stdc++.h>
using namespace std;
#define task "market"
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int N=5005;
int n,m,a[N],c[1000005],f[N];

void solve()
{
        cin>>n>>m;
        for(int i=1;i<=n;++i) cin>>a[i];
        sort(a+1,a+n+1);
        for(int i=1;i<=m;++i)
        {
                cin>>c[i];
        }
        for(int i=1;i<=n;++i) f[i]=2e9;
        for(int i=m-1;i>=1;--i)
        {
                c[i]=min(c[i],c[i+1]);
        }
        f[0]=0;
        for(int i=1;i<=n;++i)
        {
                f[i]=f[i-1]+c[1];
                for(int j=1;j<i;++j)
                {
                        f[i]=min(f[i],f[j-1]+c[a[i]-a[j]+1]);
                }
        }

        cout<<f[n];
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



