#include<bits/stdc++.h>

using namespace std;

#define task "lqd"
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

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,b,a) for(int i=(b);i>=(a);--i)
#define REP(i,a,b) for(int i=(a);i<(b);++i)

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;

const int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const int dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1000000007; /// 998244353
const int base=311;

const int N=16+5;

int a[N][N],n;
ll dp[70000],w[70000];

void biot()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j) cin>>a[i][j];

    for(int i=0;i<(1<<n);++i) dp[i]=-1e15;

    dp[0]=0;

    for(int mask=0;mask<(1<<n);++mask)
    {
        for(int i=1;i<=n;++i) if(BIT(mask,i-1))
        for(int j=i+1;j<=n;++j) if(BIT(mask,j-1)) w[mask]+=a[i][j];
    }
//    for(int i=0;i<(1<<n);++i) cout<<w[i]<<' ';
//    cout<<endl;
    for(int mask=1;mask<(1<<n);++mask)
    {
        for(int premask=mask;premask>=0;premask=((premask-1)&mask))
        {
            int nmask=(mask^premask);
            dp[mask]=max(dp[mask],dp[premask]+w[nmask]);
            if(premask==0) break;
        }
    }
//    for(int i=0;i<(1<<n);++i) cout<<dp[i]<<' ';
//    cout<<endl;
    cout<<dp[(1<<n)-1];
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

