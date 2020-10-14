#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "VMROPES"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int oo = 2e9;
const ll inf = 1e15;
const int N = 2e5;

vector<int> q;
int n , a, b ,k;
void check(int val)
{
    vector<int> tmp;
    tmp.clear();
    while (val > 0) {
        tmp.push_back(val % 10);
        val /= 10;
    }
    reverse(tmp.begin(),tmp.end());
    for (int i = 1; i < tmp.size(); ++i) {
        if (abs(tmp[i] - tmp[i - 1]) > k) return;
    }
    q.push_back(val);
}
void solve()
{

    cin >> n >> k >> a >> b;
    for (int i = a; i <= b; ++i) {
        check(i);
    }

    cout << q.size();

}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.










