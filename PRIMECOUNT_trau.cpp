#include<bits/stdc++.h>
using namespace std;
unsigned long long i,l,r,t,isPrime[1000000];
long long max(long long a, long long b)
{
    if (a>b ){ return a;}
    else {return b;};
}
int Prime(unsigned long long a, unsigned long long b)
{
    int res=0;
    for (int i=a; i<=b; i++)
    {
        isPrime[i-a]=1;
    }
    int i=2, j=0;
    a=max(a,2);

    while (i*i<=b)
    {
        j=max(i*i,(a+i-1)/i*i);
        while (j<=b)
        {
            isPrime[j-a]=0;
            j+=i;
        }
        i++;
    }
    for(int i=a; i<=b; i++)
    {
        res+=isPrime[i-a];
    }
    return res;
}
int main()
{
        freopen("PRIMECOUNT.inp","r",stdin);
        freopen("PRIMECOUNT.out","w",stdout);
        scanf("%d",&t);
        while (t>0)
        {
            t--;
            scanf("%d%d",&l,&r);
            cout<<Prime(l,r)<<endl;
        }
}
