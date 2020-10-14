#include<bits/stdc++.h>

using namespace std;

#define task "phantich"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

const int N = 1e5 + 5;
int f[N];
vector<int> q,ans;
void sang()
{
    f[1] = 1; f[0] = 1;
    for (int i = 2; i <= sqrt(N); ++i) {
        if (!f[i]) {
            int j = i + i;
            while (j <= N) {
                f[j] = 1;
                j += i;
            }
        }
    }
    for (int i = 2; i <= N; ++i)
    if (!f[i]) {
        q.push_back(i);
    }
}
void PrimeFact(int n)
{
    if (!f[n]) {
        ans.push_back(n);
        return;
    }
    int k = n;
    for (int i = 0; i < q.size(); ++i) {
        if (q[i] > sqrt(n)) break;
        if (k % q[i] == 0) {
            while (k % q[i] == 0) {
                ans.push_back(q[i]);
                k /= q[i];
            }
        }
    }

    if (k > 1) ans.push_back(k);
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    sang();
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        PrimeFact(i);
    }
    sort(ans.begin(),ans.end());
    ans.push_back(0);
    int d = 1;
    for (int i = 0 ; i < ans.size() - 1; ++i) {
        if (ans[i] != ans[i + 1]) {
            cout << ans[i] << ' ' << d << '\n';
            d = 1;
        }
        else ++d;
    }
}










