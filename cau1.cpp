#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define nhat "cau1"
#define ll long long
#define db double
#define For(i,a,b) for(int i=a;i<=b;i++)
#define FOr(i,a,b) for(int i=a;i>=b;i--)
const int mm=2e5+5,oo=2e9-1;
int n,m,k;
int a[mm],f[mm][3];
int main()
{
//    freopen(nhat".inp","r",stdin);
//    freopen(nhat".out","w",stdout);
    scanf("%d %d %d",&m,&n,&k);
    int vt=-k;
    For(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    f[1][1]=k; f[1][2]=k;
    For(i,2,n)
    {
        int mi=oo,mi1=oo;
        mi1=min(mi1,f[i-1][2]+k);
        if(a[i]-a[i-1]<k) mi1=min(mi1,f[i-1][1]+a[i]-a[i-1]);
        For(j,1,i-1)
        {
            if(a[i]-a[j]<k-1) mi=min(mi,min(f[j][1]+a[j]-a[i]+k,f[j][2]+a[i]-a[j]+1));
            else
            {
                if(a[i]-a[j+1]<=k-1) mi=min(mi,f[j][2]+k);
                if(a[i]-a[j]<2*k-1) mi=min(mi,f[j][1]+a[i]-a[j]-k+1);
            }
        }
        f[i][2]=mi; f[i][1]=mi1;
    }
    printf("%d",f[n][2]);
}
