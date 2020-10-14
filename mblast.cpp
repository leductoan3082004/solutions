#include<bits/stdc++.h>
using namespace std;
#define task "mblast"
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

string s,t;
int n,m,k,dp[4005][4005];
void solve()
{
    cin>>s>>t>>k;
    s=' '+s;
    t=' '+t;
    n=s.size()-1, m=t.size()-1;
    dp[0][0]=0;
    for(int i=1;i<=(m+n);++i) dp[i][0]=k*i;
    for(int i=1;i<=(m+n);++i) dp[0][i]=k*i;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j) dp[i][j]=min({dp[i-1][j]+k,dp[i][j-1]+k,dp[i-1][j-1]+abs(s[i]-t[j])});
    cout<<dp[n][m];
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





