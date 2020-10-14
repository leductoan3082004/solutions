#include<bits/stdc++.h>

using namespace std;

#define task "mmarr"
#define fi first
#define se second
#define fore(i,a,b) for(int i=(int)a;i<=(int)b;++i)
#define ford(i,a,b) for(int i=(int)a;i>=(int)b;--i)

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=300005;
int n,a[mxn];
void ILYPTV()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    int cnt=1;
    ll ans=0;
    a[n+1]=a[n]+1;
    for(int i=2;i<=n+1;++i)
    {
        if(a[i]==a[i-1]) ++cnt;
        else
        {
            ans+=1LL*cnt*(cnt+1)/2;
            cnt=1;
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
    ILYPTV();
}






