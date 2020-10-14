#include<bits/stdc++.h>
using namespace std;
#define task "prizes"
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int N=100005;
int n,k;
int a[N];
ll f[N],l[N],r[N];

void solve()
{
        cin>>n>>k;
        for(int i=1;i<=n;++i)
        {
                cin>>a[i];
                f[i]=f[i-1]+a[i];
        }
        fill(l,l+n+2,-1);
        fill(r,r+n+2,-1);
        for(int i=k;i<=n;++i)
        {
                l[i]=max(l[i-1],f[i]-f[i-k]);
        }
//        cout<<l[3]<<endl;
        for(int i=n-k+1;i>=1;--i)
        {
                r[i]=max(r[i+1],f[i+k-1]-f[i-1]);
        }
        ll ans=1e16;
        for(int i=k;i<=n;++i)
        {
                ll tmp=max(l[i-k],r[i+1]);
                if(tmp!=-1) ans=min(ans,tmp);
//                if(i==11)
//                {
//                        cout<<i<<' '<<r[i+1]<<endl;
//                        cout<<ans<<' '<<x<<endl;
//                }
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



