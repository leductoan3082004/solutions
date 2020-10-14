#include<bits/stdc++.h>
using namespace std;
#define task "aeqlb"
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
    int a,b;
    cin>>a>>b;
    while(a<b)
    {
        if((b-a)%2==0) b=a;
        else a*=2;
    }
    if(a==b) cout<<"YES";
    else cout<<"NO";
    cout<<'\n';
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





