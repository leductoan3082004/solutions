#include<bits/stdc++.h>
using namespace std;
#define task "brothers"
#define lwb lower_bound
#define upb upper_bound
#define ar array
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int N=205;
int n,m,a[N][N],dp[N][N][2*N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j) cin>>a[i][j];

    for(int k=0;k<=m+n;++k)
    for(int i=0;i<=n;++i)
    for(int j=0;j<=n;++j) dp[i][j][k]=-1e9;

    dp[1][2][1]=a[1][2]+a[2][1];
    for(int k=2;k<=m+n-2;++k)
    {
        for(int i1=1;i1<=n;++i1)
        {
            for(int i2=1;i2<=n;++i2)
            {
                int j1=k-i1+2, j2=k-i2+2;
                if(i1>=1&&i1<=n&&i2>=1&&i2<=n&&j1>=1&&j1<=m&&j2>=1&&j2<=m) {}
                else continue;
                if(i1==i2&&j1==j2) continue;
                if(i1>i2&&)
                int tmp=-1e9;
                tmp=max(tmp,dp[k-1][i1][i2]);

            }
        }
    }
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





