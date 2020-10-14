#include<bits/stdc++.h>

using namespace std;

#define task "cf"
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

const int N=2005+5;

int n,m;
string s;
ll dp[N][N][2];

void biot()
{
    cin>>n>>m>>s;
    s=' '=s;
    if(n%2==1)
    {
        cout<<0;
        return;
    }
    int sum=0;
    for(int i=1;i<=m;++i) sum+=(s[i]=='('?1:-1);

    dp[0][0][0]=1;
    for(int i=0;i<=n-m;++i)
    {
        for(int j=0;j<=)
    }
    cout<<dp[n-m][0][1];
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

