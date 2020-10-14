#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")

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

const int mod=1e9+7;
const int N=1e3;


ll Power(int x,int y)
{
    ll ans=1;
    for (ll t=x;y;y>>=1)
    {
        if (y&1) ans=(ans*t);
        t=(t*t);
    }
    return ans;
}
int Rev(int x)
{
    return Power(x,mod-2);
}
map<ll,int> M[3];
int a[2][N+5],n;
int f[N+5][N+5];
int mx[N+5][N+5];
int l[3][N+5];
ll d[3];
int main()
{
//    freopen("DTA.inp","r",stdin);
//    freopen("DTA.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[0][i];
    for (int i=1;i<=n;i++) cin>>a[1][i];

    M[0][0]=1,M[1][0]=1,M[2][0]=1;
    for (int i=1;i<=n;i++)
    {
        d[0]+=a[0][i],d[1]+=a[1][i],d[2]=d[0]+d[1];
        for (int j=0;j<3;j++)
        {
            l[j][i]=M[j][d[j]];
            M[j][d[j]]=i+1;
        }
    }
//    for (int i=1;i<=n;i++,cout<<endl)
//    for (int j=0;j<=2;j++) cout<<l[j][i]<<' ';
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
    {
//        f[i][j]=mx[i-1][j-1];
        mx[i][j]=max(mx[i-1][j],mx[i][j-1]);
        for (int u=0;u<=2;u++)
        {
            for (int v=0;v<=2;v++)
            {
                int x=i,y=j,dem=0;
                if (u<2&&v<2)
                {
    //                if (u==0) x--;
    //                if (v==0) y--;
                    if (u==1) if (l[0][x]) x=l[0][x]-1,dem++; else continue;
                    if (v==1) if (l[1][y]) y=l[1][y]-1,dem++; else continue;
                    f[i][j]=max(f[i][j],mx[x][y]+dem);
                }
                else
                {
                    if (l[2][x]&&u==2&&v==2&&x==y) x=y=l[2][x]-1,dem++;
                    else continue;
                    f[i][j]=max(f[i][j],mx[x][y]+dem);
                }
            }
        }

        mx[i][j]=max(f[i][j],mx[i][j]);
    }
//    for (int i=1;i<=n;i++,cout<<"\n")
//    for (int j=1;j<=n;j++) cout<<f[i][j]<<' ';
    cout<<mx[n][n];
}
