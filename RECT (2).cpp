#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define ll long long
#define ld double
#define up_b upper_bound
#define low_b lower_bound
#define pb push_back
#define mp make_pair

typedef pair<int,int> pii;

const int N=3e2;
int m,n;
bool a[N+5][N+5];
int link[N+5][N+5];
int ans[N+5][N+5];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("rect.inp","r",stdin);
    freopen("rect.out","w",stdout);
    cin>>m>>n;
    for (int i=1;i<=m;i++)
    for (int j=1;j<=n;j++) cin>>a[i][j];
    for (int i=1;i<=m;i++)
    for (int j=n,x=n+1;j>=1;j--)
    {
        if (a[i][j]) x=j;
        link[i][j]=x-1;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) cout << link[i][j] << ' ';
        cout << endl;
    }
    cout << endl;

    for (int i=1;i<=m;i++)
    for (int j=1;j<=n;j++)
    for (int x=i,r=n+1;x<=m;x++)
    {
        if (a[x][j]) break;
        r=min(r,link[x][j]);
        ans[x-i+1][1]++;ans[x-i+1][r-j+2]--;
    }

    for (int i=1;i<=m;i++,cout<<"\n")
    for (int j=1;j<=n;j++)
    ans[i][j]+=ans[i][j-1],cout<<ans[i][j]<<' ';

}
