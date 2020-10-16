#include<bits/stdc++.h>

using namespace std;

#define task "DOMINO"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(),(v).end()
#define endl '\n'

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;

const int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const int dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};

const ll mod=1000000007; /// 998244353
const int base=311;

const int N=1005;

int n;
ll dp[N][10];

void add(ll &a, ll b)
{
    a=(a+b)%mod;
}
void solve()
{
    cin>>n;
    if(n&1)
    {
        cout<<0;
        return;
    }
    for(int mask=0;mask<8;++mask)
    {
        dp[1][mask]=1;
    }
    for(int i=2;i<=n;++i)
    {
        add(dp[i][0],dp[i-1][7]);
        add(dp[i][1],dp[i-1][6]);
        add(dp[i][3],(dp[i-1][7]+dp[i-1][4])%mod);
        add(dp[i][4],dp[i-1][3]);
        add(dp[i][6],(dp[i-1][7]+dp[i-1][1])%mod);
        add(dp[i][7],(dp[i-1][3]+dp[i-1][6]+dp[i-1][0])%mod);
    }
    cout<<dp[n][7];
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







