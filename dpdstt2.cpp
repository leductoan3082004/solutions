#include<bits/stdc++.h>
using namespace std;
#define task "dpdstt2"
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int N=100005;
int n,a[N],f[1005],dp[N*10];
vector<int> p;
void sang()
{
    f[0]=1;
    f[1]=1;
    for(int i=2;i*i<=1000;++i)
    {
        if(f[i]==0) for(int j=i*i;j<=1000;j+=i) f[j]=1;
    }
    for(int i=2;i<=1000;++i) if(!f[i]) p.push_back(i);
}
vector<int> factor(int k)
{
    vector<int> res;
    res.clear();
    for(int i:p)
    {
        if(i*i>k) break;
        if(k%i==0) res.push_back(i);
        while(k%i==0) k/=i;
    }
    if(k>1) res.push_back(k);
    return res;
}
void solve()
{
    sang();
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        vector<int> snt=factor(a[i]);
//        for(int j:snt) cout<<j<<' ';
//        cout<<endl;
        int mx=0;
        for(int j:snt) mx=max(mx,dp[j]+1);
        for(int j:snt) dp[j]=max(dp[j],mx);
        ans=max(ans,mx);
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
        solve();
}



