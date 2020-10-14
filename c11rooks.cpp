#include<bits/stdc++.h>
using namespace std;
#define task "c11rooks"
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define BIT(x, i) (((x) >> (i)) & 1)
#define lb lower_bound
#define ub upper_bound
#define lla(v) (v).begin(),(v).end()
#define zs(v) (v).size()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ar array
#define endl '\n'
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1000000007; /// 998244353
const int base=311;
const int N=1e3+5;

int n,a[N][N],f[N][N],g[N][N];
void solved()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
    {
        cin>>a[i][j];
        f[i][j]=f[i][j-1]+a[i][j];
    }
    for(int j=1;j<=n;++j)
    {
        for(int i=1;i<=n;++i)
            g[i][j]=g[i-1][j]+a[i][j];
    }
    int ans=0;
    for(int i=2;i<=2;++i)
    for(int j=3;j<=3;++j)
    {
        int pre=0,val=f[i][n]+f[j][n];
        if(i==j) val-=f[i][n];
        for(int k=1;k<=n;++k)
        {
            int cot=g[n][k];
            if(i==j)
            {
                ans=max(ans,pre+val+cot-2*a[i][k]);
                pre=max(pre,cot-2*a[i][k]);
            }
            else
            {
                ans=max(ans,pre+val+cot-a[j][k]);
                pre=max(pre,cot-a[i][k]);
                cout<<k<<' '<<pre<<endl;
            }
        }
        pre=0;
        for(int k=1;k<=n;++k)
        {
            int cot=g[n][k];
            if(i==j)
            {
                ans=max(ans,pre+val+cot-2*a[i][k]);
                pre=max(pre,cot-2*a[i][k]);
            }
            else
            {
                ans=max(ans,pre+val+cot-a[i][k]);
                pre=max(pre,cot-a[j][k]);
            }
        }
    }
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
    solved();
}







