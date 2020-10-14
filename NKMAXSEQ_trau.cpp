/*https://bom.to/nxtvde2k1m4l*/
#include<bits/stdc++.h>
using namespace std;
#define task "NKMAXSEQ"
#define debug(a) cout << a << '\n'
#define uwu cout << '\n';
typedef pair<int,int> ii;
void init()

{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".ans","w",stdout);
}
int main()
{
    init();
    int n,p;
    cin >> n >> p;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    int ans = -1;
    for (int i = 1; i <= n; i ++) {
        long long k = 0;
        for (int j = i; j <= n; j ++) {
            k += a[j];
            if (k >= p) {
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans;
}


