#include<bits/stdc++.h>
using namespace std;
#define task "qbpoint"
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

int n;
ll ans=0;
pii a[2005];

void solve(int p)
{
    vector<ld> q;
    q.clear();
    for(int i=p+1;i<=n;++i)
    {
        int x=a[i].fi-a[p].fi, y=a[i].se-a[p].se;
        if(y==0) q.push_back(1e9);
        else q.push_back((ld)x/y);
    }
    sort(q.begin(),q.end());
    int d=0;
    for(int i=0;i<q.size();++i)
    {
        ++d;
        if(i==q.size()-1||q[i]!=q[i+1])
        {
            ans+=d*(d-1)/2;
            d=0;
        }
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i].fi>>a[i].se;
    for(int i=1;i<=n;++i) solve(i);
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





