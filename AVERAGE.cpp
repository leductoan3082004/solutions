#include<bits/stdc++.h>

using namespace std;

#define task "uwu"
#define fi first
#define se second
#define fore(i,a,b) for(int i=(int)a;i<=(int)b;++i)
#define ford(i,a,b) for(int i=(int)a;i>=(int)b;--i)

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=100005;
int n,a[mxn],mx;

void ILYPTV()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    int cnt=0,ans=0;
    for(int i=1;i<=n;++i)
    {
        if(a[i]==mx) ++cnt;
        else cnt=0;
        ans=max(ans,cnt);
    }
    cout<<mx;
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






