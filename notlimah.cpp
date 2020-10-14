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
const int N=1e6;


ll Power(int x,ll y)
{
    ll ans=1;
    for (ll t=x;y;y>>=1)
    {
        if (y&1) ans=(ans*t)%mod;
        t=(t*t)%mod;
    }
    return ans;
}
int Rev(int x)
{
    return Power(x,mod-2);
}
int fw[N+5],n,m;
int link[N+5],a[N+5],b[N+5],linkb[N+5];
void update(int x)
{
    for (;x<=n;x+=x&-x) fw[x]++;
}
int get(int x)
{
    int ans=0;
    for (;x;x-=x&-x) ans+=fw[x];return ans;
}
string s;

int main()
{
//    freopen("notlimah.inp","r",stdin);
//    freopen("notlimah.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    if (m==n+1)
    {
        ll ans=1;
        for (int i=2;i<=n;i++) ans=(ans*i)%mod;
//        cout<<ans<<endl;
//        cout<<Power(2,1ll*(n-2)*(n-1)/2)<<endl;
        ans=(ans*Power(2,1ll*(n-2)*(n-1)/2))%mod;
        cout<<ans;
    }
}
