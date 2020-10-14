#include<bits/stdc++.h>
using namespace std;
#define task "word"
#define lb lower_bound
#define ub upper_bound
#define ALL(v) (v).begin(),(v).end()
#define zs(v) (int)(v).size()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define cntbit __builtin_popcountll
#define BIT(x, i) (((x) >> (i)) & 1)
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
const int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const int dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1000000007; /// 998244353
const int base=311;
const int N=1e5+5;

map<string,int> M;

void biot()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        string s; cin>>s;
        M[s]=1;
    }
    int m; cin>>m;
    for(int i=1;i<=m;++i)
    {
        string s; cin>>s;
        if(M.count(s)) cout<<"YES";
        else cout<<"NO";
        cout<<'\n';
    }
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











