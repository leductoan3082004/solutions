#include<bits/stdc++.h>
using namespace std;
#define task "maugiao"
#define lb lower_bound
#define ub upper_bound
#define ALL(v) (v).begin(),(v).end()
#define zs(v) int((v).size())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,b,a) for(int i=(b),_a=(a);i>=_a;--i)
#define FOR_(i,a,b) for(int i=(a),_b=(b);i<_b;++i)
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1000000007; /// 998244353
const int base=311;
const int N=1e5+5;

int n,a[25][25];
ll dp[(1<<20)+5],way[(1<<20)+5];

int BIT(int mask, int i)
{
    return mask>>i&1;
}
void biot()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j) cin>>a[i][j];
    for(int i=1;i<=n;++i) way[1<<(i-1)]=1;
    for(int mask=1;mask<(1<<n);++mask)
    {
        int k=__builtin_popcountll(mask);
        for(int i=1;i<=n;++i)
        {
            if(BIT(mask,i-1))
            {
                dp[mask]=max(dp[mask],dp[mask-(1<<(i-1))]+a[k][i]);
            }
        }
        for(int i=1;i<=n;++i)
        {
            if(BIT(mask,i-1))
            {
                if(dp[mask]==dp[mask-(1<<(i-1))]+a[k][i])
                {
                    way[mask]+=way[mask-(1<<(i-1))];
                }
            }
        }
    }
    cout<<dp[(1<<n)-1]<<' '<<way[(1<<n)-1];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    biot();
}









