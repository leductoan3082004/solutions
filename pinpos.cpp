#include <bits/stdc++.h>
using namespace std;
long long n,a,b,u,v,x,y,l,r,oo=999999999;
long long ma,mb,mu,mv,mx,my,ml,mr,kq;
long long mt=-oo,mp=-oo,mc=oo,md=oo;
int main()
{
    freopen("pinpos.inp","r",stdin);
    freopen("pinpos.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&a,&b,&u,&v,&x,&y,&l,&r);
        ma=a-b;
        mb=a+b;
        mu=u-v;
        mv=u+v;
        mx=x-y;
        my=x+y;
        ml=l-r;
        mr=l+r;
        mt=max(mt,min(ma,min(mu,min(mx,ml))));
        mp=max(mp,min(mb,min(mv,min(my,mr))));
        mc=min(mc,max(ma,max(mu,max(mx,ml))));
        md=min(md,max(mb,max(mv,max(my,mr))));
    }
    kq=(mc-mt-1)*(md-mp-1);
    if(kq<=0) printf("0");
    else
    {
        if((mt+mp)%2==0) printf("%lld",(kq+1)/2);
        else
        {
            printf("%lld",kq/2);
        }
    }
}
