
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

const int mod=998244353;
const int N=1e6;
vector<int> f[40000];
int n,k;
int main()
{
//    freopen("GIFT.inp","r",stdin);
//    freopen("GIFT.out","w",stdout);
    cin>>n>>k;
    for (int i=0;i<=n+1;i++)
    for (int j=0;j<=k+1;j++) f[i].pb(0);

    for (int j=0;j<=k;j++) f[0][j]=1;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=k;j++)
    {
        f[i][j]=(f[i][j-1]+f[i-1][j-1])%mod;
        if (j-2>=0) f[i][j]=(f[i][j]+f[i-1][j-2])%mod;
    }
//    for (int i=1;i<=n;i++,cout<<endl)
//        for (int j=1;j<=k;j++) cout<<f[i][j]<<' ';
    for (int i=1;i<=k;i++) if (i>n) cout<<0<<' ';else cout<<f[i][n]<<' ';
}

