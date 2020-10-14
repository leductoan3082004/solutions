#include<bits/stdc++.h>
using namespace std;
#define task "ham12"
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

void solve()
{
        int n,m,k;
        string la;
        cin>>n>>m>>k;
        cin>>la;
        int ans=3000;
        for(int i=1;i<=k;++i)
        {
                string mau;
                cin>>mau;
                for(int p=0;p<n;++p)
                {
                        int j=p, cnt=0, cost=0;
                        while(cnt<m)
                        {
                                if(mau[cnt]!=la[j]) ++cost;
                                ++cnt;
                                ++j;
                                if(j==n) j=0;
                                if(cost>ans) break;
                        }
                        ans=min(ans,cost);
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
    solve();
}



