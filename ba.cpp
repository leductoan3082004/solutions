
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


ll Power(int x,int y)
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
int n,k,x;
map<int,ll> P[2];
ll C(int x,int y)
{
    int mx=max(y-x,x);
    int mn=min(y-x,x);
    ll ans=1;
    for (int i=mx+1;i<=y;i++) ans=(ans*i)%mod;
    ll res=1;
    for (int i=1;i<=mn;i++) res=(res*i)%mod;
    return (ans*Rev(res))%mod;
}
ll cal(int x,int M,int c)
{
    if (x==0)
    {
        if (M==0) return 1;
        return 0;
    }
    if (x==1)
    {
        int d=0;
        for (int i=0;i<=9;i++) if (i!=c&&i%3==M) d++;
        return d;
    }
    ll ans=0;
    ll res[4];
    if (P[0][x/2]==0) res[0]=cal(x/2,0,c),P[0][x/2]=res[0];
    else res[0]=P[0][x/2];
    if (P[1][x/2]==0) res[1]=cal(x/2,1,c),P[1][x/2]=res[1];
    else res[1]=P[1][x/2];
    res[2]=(Power(9,x/2)-res[0]-res[1]+2*mod)%mod;
    if (x%2==0)
    {
        for (int i=0;i<=2;i++)
        ans=(ans+res[i]*res[(M+3-i)%3])%mod;
    }
    else
    for (int r=0;r<=9;r++)
    {
        if (r==c) continue;
        for (int i=0;i<=2;i++)
        ans=(ans+res[i]*res[(M-r-i+12)%3])%mod;
    }
    return ans;
}
int main()
{
//    freopen("BA.inp","r",stdin);
//    freopen("BA.out","w",stdout);
    cin>>n>>k>>x;
    ll ans=0;
    int T=(3-(k*x)%3)%3;
    if (x!=0)
        ans=(C(k-1,n-1)*cal(n-k,T,x))%mod;
    for (int i=1;i<=9;i++)
    {
        if (i==x) continue;
    //       cout<<ans<<endl;
        ans=(ans+(C(k,n-1)*cal(n-k-1,(T-i+9)%3,x))%mod)%mod;
    }
    cout<<ans;
}
