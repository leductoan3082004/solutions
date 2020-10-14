#include<bits/stdc++.h>
using namespace std;
#define task "CAVERAGE"
#define lb lower_bound
#define ub upper_bound
#define ALL(v) (v).begin(),(v).end()
#define zs(v) (int)(v).size()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define cntbit __builtin_popcountll
#define BIT(x, i) (((x) >> (i)) & 1)
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
const int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const int dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1000000007; /// 998244353
const int base=311;
const int N=1e5+5;
const int tt=2500;

int a[55],A,n;
ll dp[2][tt*2+1000];

void biot()
{
    cin>>n>>A;
    int sum=0;
    for(int i=1;i<=n;++i) cin>>a[i],a[i]-=A,sum+=a[i];

    dp[0][tt]=1;
//    for(int i=1;i<=n;++i) cout<<a[i]<<' ';
//    cout<<'\n';
    for(int i=1;i<=n;++i)
    {
        for(int j=-2500;j<=2500;++j)
        {
            dp[1][tt+j]+=dp[0][tt+j];
            dp[1][tt+j+a[i]]+=dp[0][tt+j];
        }
        for(int j=-2500;j<=2500;++j)
        {
            dp[0][tt+j]=dp[1][tt+j];
            dp[1][tt+j]=0;
        }
    }
//    cout<<dp[1][tt-1]<<endl;
    cout<<dp[0][tt]-1;
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
    return 0;
}











