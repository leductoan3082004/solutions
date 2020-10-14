#include<bits/stdc++.h>
using namespace std;
#define task "mcoins"
#define lwb lower_bound
#define upb upper_bound
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> p2i;
typedef pair<int,p2i> p3i;
typedef pair<p2i,p2i> p4i;

int k,l,n,dp[1100000];
void solve()
{
    cin>>k>>l>>n;
    dp[0]=0;
    for(int i=0;i<=1e6;++i)
    {
        if(!dp[i])
        {
            dp[i+k]=1;
            dp[i+l]=1;
            dp[i+1]=1;
        }
    }
//    for(int i=1;i<=12;++i) cout<<dp[i]<<' ';
//    cout<<endl;
    for(int i=1;i<=n;++i)
    {
        int x; cin>>x;
        if(dp[x]) cout<<"A"; else cout<<"B";
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






