#include<bits/stdc++.h>

using namespace std;

#define task "LCMLIMIT"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

int d[] = {2,3,5,7,9,11,13,17,19,23,29};
int n;
vector<int> q;
void dq(int id, ll sum , int num , int div)
{
    if (sum >  1e6) return;
    if (div >= n) {
        int k = sqrt(sum);
        if (k * k == sum) return;

        for (int i = 1; i <= sqrt(sum); ++i) {
            if (sum % i == 0) {
                q.push_back(i);
                q.push_back(sum / i);
            }
        }
        sort(q.begin(),q.end());
        for (int i = 0; i < n; ++i) cout << q[i] << ' ';
        exit(0);
    }
    dq(id,1LL * sum * d[id],num + 1,div);
    if (id < 9) dq(id + 1,sum , 0, (num + 1) * div);
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n;
    if (n == 1) cout << n ;
    else
    dq(0,1,0,1);
}










