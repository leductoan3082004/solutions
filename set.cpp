#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define ld long double
#define oo 1e16
#define fi first
#define se second
#define sp(iiii) setprecision(iiii)
#define IO ios_base::sync_with_stdio(false); cin.tie(0)
#define ms(aaaa,xxxx) memset(aaaa,xxxx,sizeof(aaaa))

int t,it,a,b,l,r,dist,k,mul,i,n;

int main(){
    cin>>t;
    for (it=1;it<=t;it++) {
        cin>>k>>a>>b;
        dist=b-a;
        mul=1;
        while ((k!=0)&&(k!=1)&&(dist%k==0)) {
            dist/=k;
            mul*=k;
            //cout<<'jhsh';
        }
        a=ceil(a/mul);
        b=ceil(b/mul);
        dist=b-a;
        cin>>n;
        for (i=1;i<=n;i++) {
            cin>>l>>r;
            if (r>l) {
                if (((r-l)%dist==0)&&(a<=l)&&(b<=r)) {
                    cout<<"YES\n";
                }
                else {
                    cout<<"NO\n";
                }
            }
            else {
                cout<<"NO\n";
            }
        }
    }
}
