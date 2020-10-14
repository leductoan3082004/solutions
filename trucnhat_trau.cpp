#include<bits/stdc++.h>

using namespace std;

#define task "trucnhat"
#define fi first
#define se second
#define fore(i,a,b) for(int i=(int)a;i<=(int)b;++i)
#define ford(i,a,b) for(int i=(int)a;i>=(int)b;--i)

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1000006;
int n;
int cal(int x)
{
    int ans=0;
    for(int i=1;i<=x;++i)
    {
        if(x%i==0) ans+=i;
    }
    return ans;
}
void ILYPTV()
{
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        if(cal(x)<2*x) ++ans;
    }
//    cout<<cal(602)<<'\n';
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".ans","w",stdout);
    }
    ILYPTV();
}






