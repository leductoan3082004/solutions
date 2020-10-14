#include<bits/stdc++.h>
using namespace std;
#define task "bwpoints"
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

int n;
int ans;
pii a[200005];
void solve()
{
        cin>>n;
        for(int i=1;i<=n;++i)
        {
                cin>>a[i].fi;
                a[i].se=0;
        }
        for(int i=1;i<=n;++i)
        {
                cin>>a[i+n].fi;
                a[i+n].se=1;
        }
        n*=2;
        sort(a+1,a+n+1);
        for(int i=1;i<n;++i)
        {
                if(a[i].se!=a[i+1].se)
                {
                        ++ans;
                        ++i;
                }
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



