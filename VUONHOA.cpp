#include<bits/stdc++.h>

using namespace std;

#define task "VUONHOA"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

int main()
{
    TL
//    freopen(task".inp","r",stdin);
//    freopen(task".out","w",stdout);

    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int u ,v;
        cin >> u >> v;
        ans = max(ans,u + v);
    }
    cout << ans;
}










