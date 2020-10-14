#include<bits/stdc++.h>

using namespace std;

#define task "task"
#define fi first
#define se second
#define fore(i,a,b) for(int i=(int)a;i<=(int)b;++i)
#define ford(i,a,b) for(int i=(int)a;i>=(int)b;--i)

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=505;
int n,a[mxn],dp[mxn][mxn],f[mxn];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];

    for(int i=1;i<=n;++i) fill(dp[i]+1,dp[i]+n+1,-1);

    for(int i=1;i<=n;++i) dp[i][i]=a[i];

    for(int len=1;len<=n;++len)
    {
        for(int i=1;i<=n;++i)
        {
            int j=i+len-1;
            if(j>n) break;
            for(int k=i;k<j;++k)
            {
                if(dp[i][k]!=-1&&dp[k+1][j]!=-1&&dp[i][k]==dp[k+1][j])
                {
                    dp[i][j]=dp[i][k]+1;
                    break;
                }
            }
        }
    }
    fill(f+1,f+n+1,2e9);
    f[0]=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=i;++j)
            if(dp[j][i]!=-1) f[i]=min(f[i],f[j-1]+1);
    }
    cout<<f[n];
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






