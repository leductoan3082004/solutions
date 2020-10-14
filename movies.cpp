#include<bits/stdc++.h>
using namespace std;

#define task "movies"
#define fi first
#define se second
#define fore(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define ford(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)

typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1e5+5;
int n,k,f[mxn],cnt[mxn];
vector<int> a;
void solve()
{
    cin>>n>>k;
    a.push_back(-1);
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    a.resize(unique(a.begin(),a.end())-a.begin());
    int na=a.size()-1;
    for(int i=2;i<na;++i)
    {
        ++cnt[a[i]];
        if(a[i-1]==a[i+1]) f[a[i]]++;
    }
    ++cnt[a[1]]; ++cnt[a[na]];
    int pos=1, ans=cnt[1]+f[1];
    for(int i=2;i<=k;++i)
    {
        if(cnt[i]+f[i]>ans)
        {
            pos=i;
            ans=f[i]+cnt[i];
        }
    }
    cout<<pos;
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


