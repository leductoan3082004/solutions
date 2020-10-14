#include<bits/stdc++.h>
using namespace std;
#define task "NAME"
#define fi first
#define se second
#define fore_(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define fore(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define ford(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

int n,m,ans=0;
string s[55];
void solve()
{
    cin>>n>>m;
    fore(i,1,n)
    {
        cin>>s[i];
        s[i]=' '+s[i];
    }

    fore(i,1,n-1)
        fore(j,1,m-1)
        {
            vector<int> a(28,0);
             fore(x,i,i+1)
                fore(y,j,j+1)
                    a[s[x][y]-'a']++;
            int ok=1;
            ok&=(a['f'-'a']==1);
            ok&=(a['a'-'a']==1);
            ok&=(a['c'-'a']==1);
            ok&=(a['e'-'a']==1);
            ans+=ok;
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


