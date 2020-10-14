#include<bits/stdc++.h>
using namespace std;
#define task "NPR"
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
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
const ll mod=1000000007; /// 998244353
const int base=311;
const int N=1e5+5;

vector<string> s;
int T[300005][30],cnt;
vector<int> End[300005];

void add(string &st, int id)
{
    int root=0;
    for(int i=0;i<zs(st);++i)
    {
        int c=st[i]-'a';
        if(T[root][c]==0) T[root][c]=++cnt;
        root=T[root][c];
        End[root].pb(id);
        sort(ALL(End));
        if(zs(End)>2) End.pop_back();
    }
}
int pos(string &s)
{
    int root=0;
    for(int i=0;i<zs(s)-1;++i)
    {
        int c=s[i]-'a';
        if(s==End[root][0])
        root=T[root][c];
    }
    return End[root];
}
void biot()
{
    while(1)
    {
        string t="";
        getline(cin,t);
        if(t=="") break;
        s.pb(t);
    }
    for(int i=0;i<=300000;++i) End[i]=1e9;
    sort(ALL(s));
    for(int i=0;i<zs(s);++i)
    {
        reverse(ALL(s[i]));
        add(s[i],i);
        reverse(ALL(s[i]));
    }
    while(1)
    {
        string t="";
        cin>>t;
        reverse(ALL(t));
        if(t=="") break;
        int id=pos(t);
        cout<<s[id]<<'\n';
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











