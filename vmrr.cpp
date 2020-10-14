#include<bits/stdc++.h>
using namespace std;
#define task "vmrr"
#define lwb lower_bound
#define upb upper_bound
#define ar array
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ALL(v) (v).begin(), (v).end()
#define rep(i,a,b) for(ll i=(a),_b=(b);i<=_b;++i)
#define repd(i,a,b) for(ll i=(a),_b=(b);i>=_b;--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

void solve()
{
    string s;
    getline(cin,s);
    string t;
    getline(cin,t);
    ll ans=0, cnt1=0;
    for(char i:s)
    {
        if(i==t[1]) ans+=cnt1;
        if(i==t[0]) ++cnt1;
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





