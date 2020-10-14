#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "task"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define rep_(i,a,b) for (int i = a; i >= b; --i)

typedef long long ll;
typedef pair<int,int> pii;

void solve()
{
    int n;
    cin>>n;
    vector<int> a(7);
    a[1]=500;
    a[2]=200;
    a[3]=100;
    a[4]=50;
    a[5]=20;
    a[6]=10;
    rep(i,1,6)
    {
        int k=n/a[i];
        cout << k << ' ';
        n-=k*a[i];
    }
}
int main()
{
    TL
//    freopen(task".inp","r",stdin);
//    freopen(task".out","w",stdout);
    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.











