#include<bits/stdc++.h>

using namespace std;

#define task "3ONES"
#define fi first
#define se second
#define fore(i,a,b) for(int i=(int)a;i<=(int)b;++i)
#define ford(i,a,b) for(int i=(int)a;i>=(int)b;--i)

typedef long long ll;
typedef pair<int,int> pii;

int n;
string s;

void ILYPTV()
{
    cin>>n;
    cin>>s;
    s=' '+s;
    int cnt=0, ans=0, j=1;
    for(int i=1;i<=n;++i)
    {
        cnt+=(s[i]=='1');
        while(cnt>=3&&j<i)
        {
            if(cnt==3&&s[j]=='1') break;
            cnt-=(s[j]=='1');
            ++j;
        }
//        cout<<j<<' '<<i<<' '<<cnt<<'\n';
        ans=max(ans,i-j+1);
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






