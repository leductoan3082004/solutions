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

typedef pair<ld,int> pii;

const int mod=1e9+7;
const int N=1e5;


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
int n;
ll k;
pii a[N+5];
pii U[N+5],V[N+5];
//ll p[N+5];
pii b[N+5];
int fw[N+5];
void update(int x)
{
    for (;x<=n;x+=x&-x) fw[x]++;
}
int get(int x)
{
    int ans=0;for (;x;x-=x&-x) ans+=fw[x];
    return ans;
}
int val(ld T)
{
    for (int i=1;i<=n;i++) b[i]=mp(a[i].X+T*a[i].Y,i);
    sort(b+1,b+n+1);
//    for (int i=1;i<=n;i++) p[i]=b[i].X;
//    int dem=unique(p+1,p+n+1)-p-1;
//    for (int i=1;i<=dem;i++) M[p[i]]=i;
    int ans=0;
    for (int i=1;i<=n;i++) fw[i]=0;
    for (int i=n;i>=1;i--)
    {
        ans+=get(b[i].Y);
        update(b[i].Y);
    }
//        for(int i=1;i<=n;++i)
//        {
//                cout<<b[i].X<<' '<<b[i].Y<<endl;
//        }
    int d=0;
//    cout<<ans<<endl;
    for (int i=1;i<=n;i++)
    {
        d++;
        if (i==n||b[i].X!=b[i+1].X)
        {
            ans+=1ll*d*(d-1)/2;
            d=0;
        }
    }
    return ans;
}
int main()
{
    freopen("TRAFFIC.inp","r",stdin);
    freopen("TRAFFIC.ans","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i].X>>a[i].Y;
    sort(a+1,a+n+1);
    ld l=0,r=2e6,TT1;
    for (int i=1;i<=100;i++)
    {
        ld mid=(l+r)/2;
        if (val(mid)<k)
        {
            TT1=mid;
            l=mid;
        }
        else r=mid;
    }
//        cout<<val(0.636364)<<endl;
    int TT2=l;
//    cout<<val(TT1)<<' '<<TT1<<endl;
    for (int i=1;i<=n;i++) U[i]=mp(a[i].X+TT1*a[i].Y,i);
    sort(U+1,U+n+1);
//    for (int i=1;i<=n;i++) cout<<U[i].X<<' '<<U[i].Y<<endl;
//    for (int i=1;i<=n;i++) V[i]=mp(a[i].X+1ll*a[i].Y*TT2,i);
    for (int i=1;i<=n-1;i++)
    {
//        cout<<abs(U[i].X-U[i+1].X)<<endl;
        if (abs(U[i].X-U[i+1].X)<=0.000000001) {cout<<U[i].Y<<' '<<U[i+1].Y;break;}
    }

}
