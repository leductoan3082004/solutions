#include<bits/stdc++.h>
using namespace std;
#define task "NAME"
#define lb lower_bound
#define ub upper_bound
#define alll(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i,b,a) for (int i = (b), _a = (a); i >= _a; --i)
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;

const int MOD=1000000007; /// 998244353
const int base=311; /// for hash actually
int pos[20],a[50];
void solved()
{
        for(int i=1;i<=9;++i) {
                int x; cin>>x;
                pos[x]=i;
        }
        for(int i=0;i<=14;++i) a[i]=i/3+2;
        for(int i=15;i<=18;++i) a[i]=7;
        for(int i=19;i<=21;++i) a[i]=8;
        for(int i=22;i<26;++i) a[i]=9;
        string s; cin>>s;
        for(int i=0;i<s.size();++i) {
                int x=s[i]-'a';
                if(i&&s[i]==s[i-1])
                        cout<<"#";
                if(i<=14) {
                        for(int j=1;j<=)
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
    solved();
}
