#include<bits/stdc++.h>
using namespace std;
#define task "nkh"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define pf pop_front
#define mp make_pair
#define zs(v) (int)(v).size()
#define BIT(x, i) (((x) >> (i)) & 1)
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(),(v).end()
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,b,a) for(int i=(b);i>=(a);--i)
#define REP(i,a,b) for(int i=(a);i<(b);++i)
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
const int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const int dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1000000007; /// 998244353
const int base=311;
const int N=200+5;

string s,t,res;
int n,m;

void doing(int last)
{
    int i=n, k=n+m;
    string ans="";
    while(i||k)
    {
        if((!i)||dp[i][k-1]==1
        {

        }
    }
}
void biot()
{
    cin>>s>>t>>res;
    reverse(ALL(s));
    reverse(ALL(t));
    reverse(ALL(res));
    n=zs(s), m=zs(t);
    s=' '+s; t=' '+t; res=' '+res;
    /// dp[i][k]
    dp[0][0]=1;
    for(int k=1;k<=n+m;++k)
    {
        for(int i=0;i<=n;++i)
        {
            if(i==0)
            {
                int can=(k-i<=m&&t[k-i]==res[k]);
                dp[i][k]|=(dp[i][k-1]&can);
            }
            else
            {
                dp[i][k]|=(dp[i-1][k-1]|s[i]==res[k]);
                int can=(k-i<=m&&t[k-i]==res[k]);
                dp[i][k]|=(dp[i][k-1]&can);
            }
        }
    }
    doing(1);
    doing(0);
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












