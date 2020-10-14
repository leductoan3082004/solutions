#include<bits/stdc++.h>
using namespace std;
#define task "insul"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define mp make_pair
#define ALL(v) (v).begin(), (v).end()
#define dembit __builtin_popcountll
#define rep(i,a,b) for (int i = (a), _b = (b); i <= _b; ++i)
#define repd(i,b,a) for (int i = (b), _a = (a); i >= _a; --i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    ll ans=0;
    rep(i,0,n-1) cin>>a[i],ans+=a[i];
    int i=0, j=n-1;
    sort(a.begin(),a.end(),greater<int>());
    /// 5 4 3 2 1
    while(i<j) ans+=a[i]-a[j],++i,--j;
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






