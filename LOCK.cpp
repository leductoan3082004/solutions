#include<bits/stdc++.h>
using namespace std;
#define task "NAME"
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

int n,cnt[30];
string s;

void solve()
{
    cin>>n;
    cin>>s;
    s=' '+s;
    int ok=1;
    FOR(i,1,n)
    {
        if(s[i]==s[i-1]) ok=0;
        ++cnt[s[i]-'0'];
    }
    int dem=0;
    FOR(i,0,9) dem+=(cnt[i]!=0);
    ok&=(dem>=5);
    cout<<ok<<'\n';
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


