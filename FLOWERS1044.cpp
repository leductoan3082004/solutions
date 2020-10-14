#include<bits/stdc++.h>
using namespace std;
#define task "FLOWERS1044"
typedef pair<int,int> ii;
typedef long long ll;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
int main()
{
    init();
    int n,m,s,pos1,pos2,Min1 = 1e9,Min2 = 1e9;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        if (x < Min1) {
            Min1 = x;
            pos1 = i;
        }
    }
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        if (x < Min2) {
            Min2 = x;
            pos2 = i;
        }
    }
    if (Min1 + Min2 > s) return cout << "0 0", 0;
    else cout << pos1 << ' ' << pos2 << '\n';
}





