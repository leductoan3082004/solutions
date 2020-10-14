#include<bits/stdc++.h>
using namespace std;
int n,a[100000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("exp737.inp","r",stdin);
    freopen("exp737.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int cong=1000000001,h=0;
    int tru=-1000000001,t=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<cong&&i%2!=0)
        {
            cong=a[i];
            h=i;
        }
        if(a[i]>tru&&i%2==0)
        {
            tru=a[i];
            t=i;
        }
    }
    int tmp=a[h];
    a[h]=a[t];
    a[t]=tmp;
    long long kq=0;
    for(int i=1;i<=n;i++)
    {
        if(i%2!=0) kq+=a[i];
        else kq-=a[i];
    }
    cout<<kq;
}
