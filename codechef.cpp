#include<bits/stdc++.h>
using namespace std;
#define task ""
#define lb lower_bound
#define ub upper_bound
#define ALL(v) (v).begin(),(v).end()
#define zs(v) int((v).size())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1000000007; /// 998244353
const int base=311;
const int N=1e5+5;

void biot()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    int ans=0, d=0;
    sort(a.begin()+1,a.end());
    for(int i=1;i<=n;++i)
    {
        ++d;
        if(i==n||a[i]!=a[i+1])
        {
            ans=max(ans,d);
            d=0;
        }
    }
    cout<<ans<<'\n';
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
    while(t--) biot();
}











