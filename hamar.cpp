#include<bits/stdc++.h>
using namespace std;
#define task "NAME"
#define fi first
#define se second
#define fore_(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define fore(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define ford(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

void solve()
{
    int n; cin>>n;
    fore(i,1,n)
        cin>>a[i];

    fore(len,1,n)
    {
        fore(i,1,n)
        {
            int j=i+len-1;
            if(j>n) break;
            fore(k,i,j-1)
            {
                if(dp[i][k]==-1||dp[k+1][j]==-1) continue;
                dp[i][j]=dp[i][k]+1;
            }
        }
    }
    vector<int> f(n+1);
    fore(i,1,n)
    {
        fore(j,1,i-1)
        {
            if(dp[i][j]!=-1)
                f[i]=max(f[i],f[j-1]+1);
        }
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

