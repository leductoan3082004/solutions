#include<bits/stdc++.h>

using namespace std;

#define task "pearltree"
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

const int N=3e5+5;

int n,color[N];
ll dp[N][20][2];
string s;
vector<int> dsk[N];

void dfs(int u, int pre)
{
    dp[u][1<<color[u]][0]=1;
    for(int v:dsk[u]) if(v!=pre)
    {
        dfs(v,u);

        for(int i=0;i<16;++i)
        for(int j=0;j<16;++j)
        {
            int val=(i|j);
            if(val==7||val==15) continue;
            dp[u][val][1]=(dp[u][val][1]+dp[u][i][0]*dp[v][j][0]%mod)%mod;
        }
        for(int i=0;i<16;++i)
        for(int j=0;j<16;++j)
        {
            if(i==7||i==15) continue;
            if(j==7||j==15) continue;
            dp[u][i][1]=(dp[u][i][1]+dp[u][i][0]*dp[v][j][0]%mod)%mod;
        }
        for(int i=0;i<16;++i)
        {
            dp[u][i][0]=dp[u][i][1];
            dp[u][i][1]=0;
        }
    }
}
void biot()
{
    cin>>n;
    cin>>s;
    for(int i=1;i<n;++i)
    {
        int u,v; cin>>u>>v;
        dsk[u].pb(v);
        dsk[v].pb(u);
    }
    for(int i=1;i<=n;++i)
    {
        if(s[i-1]=='D') color[i]=0;
        if(s[i-1]=='X') color[i]=1;
        if(s[i-1]=='L') color[i]=2;
        if(s[i-1]=='V') color[i]=3;
    }
    dfs(1,1);
//    cout<<dp[3][4][0]<<endl;
    int ans=0;
    for(int mask=0;mask<16;++mask)
    if(mask!=7&&mask!=15) ans=(ans+dp[1][mask][0])%mod;
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
    biot();
    return 0;
}

