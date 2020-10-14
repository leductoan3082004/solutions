#include<bits/stdc++.h>
using namespace std;
#define task "tera"
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
int n,L;
const int N=1005;
int a[N],b[N],c[N],d[N];
unordered_map<int,int> M1,M2;
void solve()
{
        cin>>n>>L;
        for(int i=1;i<=n;++i) cin>>a[i];
        for(int i=1;i<=n;++i) cin>>b[i];
        for(int i=1;i<=n;++i) cin>>c[i];
        for(int i=1;i<=n;++i) cin>>d[i];
        vector<int> q1;
        FOR(i,1,n) FOR(j,1,n)
        {
                q1.push_back(a[i]+b[j]);
                M1[a[i]+b[j]]++;
        }
        FOR(i,1,n) FOR(j,1,n)
        {
                M2[c[i]+d[j]]++;
        }
        ll ans=0;
        sort(q1.begin(),q1.end());
        q1.resize(unique(q1.begin(),q1.end())-q1.begin());
//        for(int i:q2) cout<<i<<' '<<M2[i]<<endl;
//        cout<<endl;
        for(int i:q1)
        {
//                cout<<i<<' ';
                ans+=1LL*M1[i]*M2[L-i];
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



