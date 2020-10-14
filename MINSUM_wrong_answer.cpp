#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    while (t--){
        ll a, b;
        cin>>a>>b;
        vector <ll> ua, ub;
        for (ll i=1;i<=ll(sqrt(a));i++){
            ll t = a/i;
            if (a % i == 0){
                ua.push_back(t);
                if (a % t == 0 && a/t != sqrt(a)){
                    ua.push_back(a/t);
                }
            }
        }
        for (ll i=1;i<=ll(sqrt(b));i++){
            ll t = b/i;
            if (b % i == 0){
                ub.push_back(t);
                if (b % t == 0 && b/t != sqrt(b)){
                    ub.push_back(b/t);
                }
            }
        }

        a = a * b, b = b/b;

        ll TM = 2e9;
        ll xa, xb;
        for (ll i=0;i<ua.size();i++){
            for (ll j=0;j<ub.size();j++){
                ll u = ua[i] * ub[j];
                ll g = __gcd(a/u, u);
                ll tt = a/u/g + u/g;
                if (tt < TM){
                    xa = a/u/g;
                    xb = u/g;
                    TM = tt;
                }
            }
        }
        if (xb < xa) swap (xa,xb);
        cout<<xa<<" "<<xb<<endl;

    }
}
