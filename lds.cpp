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

int n,i,j,res,a[1000009],vt[1000009],f[1000009];

void fs(int &x)
    {
        bool neg=false;
        register int c;
        x =0;
        c=getchar();
        if(c=='-')
        {
            neg = true;
            c=getchar();
        }
        for(;(c>47 && c<58);c=getchar())
            x = (x<<1) + (x<<3) +c -48;
        if(neg)
            x *=-1;
    }

int main(){
    IO;
    freopen("lds.inp","r",stdin);
    freopen("lds.out","w",stdout);
    res=1;
    fs(n);
    for (i=1;i<=n;i++) {
        fs(a[i]);
        vt[a[i]]=i;
        f[i]=1;
    }
    for (i=1;i*2<=n;i++) {
        for (j=2;i*j<=n;j++) {
            if (vt[i]<vt[i*j]) {
                f[i*j]=max(f[i*j],f[i]+1);
                res=max(res,f[i*j]);
            }
        }
    }
    cout<<res;
}
