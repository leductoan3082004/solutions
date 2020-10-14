#include<bits/stdc++.h>
using namespace std;
#define task "codeforces"
#define lwb lower_bound
#define upb upper_bound
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> p2i;
typedef pair<int,p2i> p3i;
typedef pair<p2i,p2i> p4i;

const int tt=2000;
const int N=2005;
int n,m,f[4000][4000][]

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        string s; cin>>s; s=' '+s;
        for(int j=1;j<=m;++j)
        {
            char c=s[j]-'a';
            f[tt+i-j][i+j][c]++;
        }
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
    solve();
}






