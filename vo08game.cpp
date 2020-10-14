#include<bits/stdc++.h>
using namespace std;
#define task "v08game"
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int N=1e5+5;
int n,m,a[N],b[N];
void solve()
{
        cin>>n;
        FOR(i,1,n) cin>>a[i];
        FOR(j,1,n) cin>>b[j];

        sort(b+1,b+n+1);
        int ans=2e9+1;
        for(int i=1;i<=n;++i)
        {

                int  k=lower_bound(b+1,b+n+1,-a[i])-b;
                if(k==n+1) --k;
//                cout<<k<<endl;
                for(int j=max(1,k-3);j<=min(n,k+3);++j) ans=min(ans,abs(a[i]+b[j]));
//                cout<<k<<endl;
        }
        cout<<ans;
//        cout<<(lower_bound(b+1,b+n+1,100)-b)<<'\n';
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



