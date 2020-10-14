
#include<bits/stdc++.h>
using namespace std;
#define task "candy"
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

int tt=100000;
int n,a[505],dp[505][200005];
void solve()
{
    cin>>n;
    int s=0;
    for(int i=1;i<=n;++i)
        cin>>a[i],s+=a[i];
    for(int i=0;i<=n;++i)
    {
        for(int j=-s;j<=s;++j)
        {
            dp[i][tt+j]=-1e9;
        }
    }
    dp[0][tt]=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=-s;j<=s;++j)
        {
            dp[i][tt+j]=dp[i-1][tt+j];
            dp[i][j+tt]=max(dp[i][tt+j],dp[i-1][tt+j-a[i]]+a[i]);
            dp[i][tt+j]=max(dp[i][tt+j],dp[i-1][tt+j+a[i]]);
        }
    }
    int ans=dp[n][tt];
    cout<<s-ans;
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





