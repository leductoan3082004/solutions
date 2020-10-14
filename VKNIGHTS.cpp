#include<bits/stdc++.h>
using namespace std;
#define task "vknights"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define pf pop_front
#define mp make_pair
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(),(v).end()

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a,b) for(int i=(a);i<(b);++i)

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
const int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const int dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1000000007; /// 998244353
const int base=311;
const int N=100+5;

int n,a[5][N],dd[5][N],way[N][10][10],dp[N][10][10];

bool check(int i, int mask)
{
    FOR(j,1,3) if(dd[i][j]&&BIT(mask,j-1)) return 0;
    return 1;
}
bool check1(int mask1, int mask2)
{
    FOR(i,1,3) FOR(j,1,3) if(BIT(mask1,i-1)&&BIT(mask2,j-1)&&abs(i-j)==2) return false;
    return true;
}
bool check2(int mask1, int mask2)
{
    FOR(i,1,3) FOR(j,1,3) if(BIT(mask1,i-1)&&BIT(mask2,j-1)&&abs(i-j)==1) return false;
    return true;
}
void biot()
{
    cin>>n;

    FOR(i,1,n)
    {
        int x; cin>>x;
        dd[i][x]=1;
    }
    /// dp[i][mask1][mask2]
    REP(mask1,0,8) REP(mask2,0,8)
    {
        if(check(1,mask1)&&check(2,mask2)&&check1(mask1,mask2))
        {
            dp[2][mask1][mask2]=CNTBIT(mask1)+CNTBIT(mask2);
            //if(mask1==6&&mask2==6) cout<<dp[2][mask1][mask2]<<endl;
            way[2][mask1][mask2]=1;
        }
    }
    FOR(i,3,n)
    {
        REP(mask,0,8) REP(mask1,0,8) REP(mask2,0,8)
        {
            if(!(check(i,mask)&&check(i-1,mask1)&&check(i-2,mask2))) continue;
            if(check1(mask,mask1)&&check2(mask,mask2)&&check1(mask1,mask2))
            {
                if(dp[i][mask][mask1]<dp[i-1][mask1][mask2]+CNTBIT(mask))
                {
                    way[i][mask][mask1]=way[i-1][mask1][mask2];
                    dp[i][mask][mask1]=dp[i-1][mask1][mask2]+CNTBIT(mask);
                }
                else if(dp[i][mask][mask1]==dp[i-1][mask1][mask2]+CNTBIT(mask))
                {
                    way[i][mask][mask1]+=way[i-1][mask1][mask2];
                }
            }
        }
    }
    int ans=0;
    ll sol=0;
    FOR(i,1,n) REP(mask1,0,8) REP(mask2,0,8)
    {
        if(CNTBIT(mask1)==0) continue;
        if(dp[i][mask1][mask2]>ans)
        {
            ans=dp[i][mask1][mask2];
            sol=way[i][mask1][mask2];
            //if(ans==4) cout<<i<<' '<<mask1<<' '<<mask2<<endl;
        }
        else if(dp[i][mask1][mask2]==ans)
        {
            sol+=way[i][mask1][mask2];
            //if(ans==4) cout<<i<<' '<<mask1<<' '<<mask2<<endl;
        }
    }
//    cout<<dp[2][]
    cout<<ans<<' '<<sol<<endl;
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


















