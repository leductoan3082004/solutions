#include<bits/stdc++.h>
using namespace std;
#define task "square"
#define lwb lower_bound
#define upb upper_bound
#define ar array
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

int n;
void solve()
{
    cin>>n;
    vector<int> s;
    s.push_back(0);
    for(int i=1;i<=n;++i)
    {
        if(sqrt(i)==(int)sqrt(i)) s.push_back(i);
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





