#include<bits/stdc++.h>
using namespace std;
#define task "daxua"
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
    ll n,m,k;
    cin>>n>>m>>k;
    ll mn=min(n,m);
    ll mx=max(n,m);
    if(mn+n-mn+m-mn>k)
    {
        cout<<-1<<'\n';
        return;
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
    int t;
    cin>>t;
    while(t--) solve();
}


