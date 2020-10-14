#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "RESORT"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<ll,ll> pii;

const ll mxn=2005;
ll dp[4][mxn][mxn],n,m,p,q,B,ans=0;
ll get(ll k, ll a, ll b, ll x, ll y)
{
    return dp[k][x][y]-dp[k][a-1][y]-dp[k][x][b-1]+dp[k][a-1][b-1];
}
void solve()
{
    cin >> n >> m >> p >> q;
    cin >> B;
    for (ll i=1; i<=n; ++i) {
        for (ll j=1; j<=m; ++j) {
            ll x; cin >> x;
            for (ll k=0; k<2; ++k) {
                dp[k][i][j] = dp[k][i-1][j]+dp[k][i][j-1]-dp[k][i-1][j-1];
            }
            if (x<B) ++dp[0][i][j];
            if (x==B) ++dp[1][i][j];
        }
    }

    ll mid=(p*q+1)/2;
//    cout << mid << endl;
    for(ll i=1; i<=n-p+1; ++i) {
        for(ll j=1; j<=m-q+1; ++j) {
            ll a=i+p-1, b=j+q-1;
            ll tmp1=get(0,i,j,a,b);
            ll tmp2=get(1,i,j,a,b);
//            cout << tmp1 << ' ' << tmp2 << endl;
            if (tmp1<mid&&tmp1+tmp2>=mid) ++ans;
        }
    }
    cout<<ans;
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.











