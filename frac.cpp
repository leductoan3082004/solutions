#include<bits/stdc++.h>
using namespace std;
long long m,kq=0;
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("frac.inp","r",stdin);
    freopen("frac.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=n-1;i++)
    {
        kq+=(m*2-1)/(n+i)-m/(n+i);
    }
    cout<<kq;
}
