#include<bits/stdc++.h>
using namespace std;
#define task "mcards"
#define lwb lower_bound
#define upb upper_bound
#define ar array
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

int c,n;
pii a[505];

void solve()
{
    cin>>c>>n;
    for(int i=1;i<=n*c;++i) cin>>a[i].fi>>a[i].se;
    vector<int> per;
    int ans=1e9;
    n*=c;
    for(int i=1;i<=c;++i) per.push_back(i);
    do {
        vector<pii> b(n+4);
        for(int i=1;i<=n;++i)
            for(int j=0;j<per.size();++j)
                if(a[i].fi==per[j]) b[i]={j,a[i].se};
        vector<int> dp(n+4,0);
        for(int i=1;i<=n;++i) {
            dp[i]=1;
            for(int j=1;j<i;++j)
            if(b[i]>=b[j]) dp[i]=max(dp[i],dp[j]+1);
        }
        for(int i=1;i<=n;++i) ans=min(ans,n-dp[i]);
    } while(next_permutation(per.begin(),per.end()));
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





