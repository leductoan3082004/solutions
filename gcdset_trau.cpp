#include <bits/stdc++.h>
#define io_faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define EL cout<<'\n'
#define pli pair<ll,ll>
#define pii pair<ll,ll>
#define fi first
#define se second
#define PROB "t"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

void file(){
	freopen(PROB".inp","r",stdin);
	freopen(PROB".ans","w",stdout);
}

// Talk less
// Love more

const int N = 20005;
int n; ll k;
ll a[N];

void solve(){
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector < ll > d;
    for (int i=1;i<=n;i++){
        if (a[i] == k){
            cout << "YES"; EL;
            return;
        }
        if (a[i] % k == 0)
            d.push_back(a[i]);
    }
    ll u = 0;
    for (int i= 0;i<d.size();i++)
        u = __gcd(u, d[i]);
    if (u == k) cout << "YES";
    else cout <<"NO";
    EL;

}

int main(){
    io_faster
    file();
    ll t = 1;
    cin >> t;
    while (t--){
        solve();
    }
}
