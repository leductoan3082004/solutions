#include<bits/stdc++.h>

using namespace std;

#define task "trucnhat"
#define fi first
#define se second
#define fore(i,a,b) for(int i=(int)a;i<=(int)b;++i)
#define ford(i,a,b) for(int i=(int)a;i>=(int)b;--i)

typedef long long ll;
typedef pair<int,int> pii;
const int N=5e6+5, mxn=1e6+5;

int n,f[N*2];

void sangnt()
{
    for(int i=2;i<=sqrt(N);++i)
    {
        if(!f[i])
        {
            for(int j=i*i;j<N;j+=i)
                if(f[j]==0) f[j]=i;
        }
    }
    for(int i=2;i<=N;++i)
        if(!f[i]) f[i]=i;
}
ll pw(int n, int k)
{
    if(k==0) return 1;
    if(k==1) return n;
    ll t=pw(n,k/2);
    if(k&1) return t*t*n;
    else return t*t;
}
ll calc(int val)
{
    ll ans=1;
    while(val>1)
    {
        int tmp=f[val],dem=0;
        while(val%tmp==0)
        {
            val/=tmp;
            ++dem;
        }
        ans*=1LL*(pw(tmp,dem+1)-1)/(tmp-1);
    }
    return ans;
}
void ILYPTV()
{
    sangnt();
    cin>>n;
    int ans=0;
//    cout<<calc(3)<<'\n';
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        if(calc(x)<2*x) ++ans;
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
    ILYPTV();
}






