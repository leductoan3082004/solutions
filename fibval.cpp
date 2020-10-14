#include<bits/stdc++.h>
using namespace std;
#define task "fibval"
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOR_(i,a,b) for(int i=(a),_b=(b);i<_b;++i)
#define bug(x) cout<<#x<<'='<<x<<'\n'
#define pb push_back
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

int ql[]={-1,1,2,3,5,1,6,7,6,6,5,4,2,6,1,7,1}; ///16
ll f[100005];

int pos(int u)
{
    int ans=u%16;
    if(ans==0) return 16;
    else return ans;
}
void solve()
{
    int u,v;
    cin>>u>>v;
    int len=v-u+1;
    if(len>=32)
    {
        cout<<len/16*16<<'\n';
        return;
    }
    for(int i=u;i<v;++i)
    {
        if(ql[pos(i)]==ql[pos(i+1)])
        {
            cout<<2<<'\n';
            return;
        }
    }
    cout<<-1<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t;
    cin>>t;
    while(t--) solve();
}



