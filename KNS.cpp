#include<bits/stdc++.h>

using namespace std;

#define task "KNS"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

bool cmp(string a, string b)
{
    return a + b > b + a;
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(),a.end(),cmp);

    for (int i = 0; i < n; ++i) cout << a[i];
}









