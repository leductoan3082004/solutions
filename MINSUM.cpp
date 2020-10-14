#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);
    int t;
    cin>>t;
    while (t--){
        int a, b;
        cin>>a>>b;
        vector <int> ua, ub;
        for (int i=1;i<=int(sqrt(a));i++){
            int t = a/i;
            if (a % i == 0){
                ua.push_back(t);
                if (a % t == 0 && a/t != sqrt(a)){
                    ua.push_back(a/t);
                }
            }
        }
        for (int i=1;i<=int(sqrt(b));i++){
            int t = b/i;
            if (b % i == 0){
                ub.push_back(t);
                if (b % t == 0 && b/t != sqrt(b)){
                    ub.push_back(b/t);
                }
            }
        }

        a = a * b, b = b/b;

        long long TM = 2e9;
        long long xa, xb;
        for (int i=0;i<ua.size();i++){
            for (int j=0;j<ub.size();j++){
                long long u = ua[i] * ub[j];
                long long g = __gcd(a/u, u);
                long long tt = a/u/g + u/g;
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
