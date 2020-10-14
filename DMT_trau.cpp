#include<bits/stdc++.h>
using namespace std;
vector<long long > a,IsPrime;
int f[10000000];
void sang()
{
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= 1000; i++ )
    if (!f[i] ) {
        int j = i * 2;
        while (j <= 1000000) {
            f[j] = 1;
            j += i;
        }
    }
    for (int i=1; i<=1000000; i++)
    if (!f[i]) IsPrime.push_back(i);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("DMT.inp","r",stdin);
    freopen("DMT.ans","w",stdout);
    sang();
    for (int i=0; i < IsPrime.size(); i++)
    if (IsPrime[i] !=3 )
    {
        a.push_back(IsPrime[i]*IsPrime[i]*9);
    }
    a.push_back(6561);
    sort(a.begin(),a.end());
//    for (int i : a) cout << i << ' ';
//    cout << endl;
    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        int l = lower_bound(a.begin(),a.end(),x) - a.begin();
        int r = upper_bound(a.begin(),a.end(),y) - a.begin() - 1;
        cout << r -l + 1  << '\n';
    }

}
