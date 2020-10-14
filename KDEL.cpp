#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "KDEL"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int mxn = 1e6;

vector<int> q;
int n, k;
void sang()
{
    vector<int> f(mxn + 5,0);
    for (int i = 2; i <= sqrt(mxn); ++i) {
        if (f[i]) continue;
        int j = i * i;
        while (j <= mxn) {
            f[j] = 1;
            j += i;
        }
    }

    for (int i = 2; i <= mxn; ++i) {
        if (!f[i]) q.push_back(i);
    }
}
void solve()
{
    sang();
//    cout << q.size() << endl;
    cin >> n >> k;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        vector<int> tmp;
        tmp.clear();
        int x = q[i];
        while (x > 0) {
            tmp.push_back(x % 10);
            x /= 10;
        }
        reverse(tmp.begin(),tmp.end());
        for (int v : tmp) a.push_back(v);
    }
    deque<int> que;
    int cnt = a.size() - k;
    for (int i = 0; i < a.size(); ++i) {
        while (!que.empty()
               && a[que.back()] < a[i] && k > 0) {
                que.pop_back();
                --k;
               }
        que.push_back(i);
    }

    for (int i = 0; i < cnt; ++i) cout << a[que.at(i)];
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.











