#include<bits/stdc++.h>
using namespace std;
#define task "pbcwri"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define pf pop_front
#define mp make_pair
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(),(v).end()
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
const int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const int dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1000000007; /// 998244353
const int base=311;
const int N=1e5+5;

int n,m,ok[1000],dd[1000];
string s,t;

void biot()
{
    cin>>n>>m;
    cin>>s>>t;
    s=' '+s;
    t=' '+t;
    for(int i=1;i<=n;++i) ok[s[i]]++;

    int ans=0;

    for(int i=1,j=1;i<=m;++i)
    {
        ++dd[t[i]];
        while(dd[t[i]]>ok[t[i]])
        {
            --dd[t[j]];
            ++j;
        }
//        cout<<i<<' '<<j<<'\n';
        if(i-j+1==n) ++ans;
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
    biot();
    return 0;
}
