#include<bits/stdc++.h>
using namespace std;
#define task "bs"
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

void solve()
{
        ld l=0, r=10000;
        for(int i=1;i<=60;++i)
        {
                ld mid=(l+r)/2.00;
                cout<<mid<<endl;
                if(mid>=50) l=mid;
                else r=mid;
        }
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



