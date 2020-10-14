#include<bits/stdc++.h>
using namespace std;
#define task "knights"
#define lwb lower_bound
#define upb upper_bound
#define ar array
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ALL(v) (v).begin(), (v).end()
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

void solve()
{
    int q,n;
    cin>>q>>n;
    ll all=1LL<<n;
    while(q--)
    {
        ll a,b;
        cin>>a>>b;
        int ok=0;
        if(a<=all/2&&b>all/2) ok=1;
        if(a>all/2&&b<=all/2) ok=1;
        if(ok) cout<<"yes\n";
        else cout<<"no\n";
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





