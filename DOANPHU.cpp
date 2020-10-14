/*https://bom.to/nxtvde2k1m4l*/
#include<bits/stdc++.h>
using namespace std;
#define task "DOANPHU"
typedef pair<int,int> ii;
typedef long long ll;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
map<int,int> a;
int main()
{
    init();
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) {
        int l, r;
        cin >> l >> r;
        if (l > r) swap(l,r);
        a[l + 1] ++;
        a[r + 1] -- ;
    }
    for (int i = -32005; i <= 32001; i ++) a[i] += a[i-1];
    int cnt = 0, ans = 1;
    for (int i = -32005; i <= 32001; i ++) {
        if (a[i]) cnt ++ ;
        else cnt = 0;
        ans = max(ans,cnt);
    }
    cout << ans;
}





