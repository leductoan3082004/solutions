#include <bits/stdc++.h>
using namespace std;
string s;
int n,m;
long long f[35];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("CHUSO.inp","r",stdin);
    freopen("CHUSO.ans","w",stdout);
    cin>>s;
    cin>>n>>m;
    f[0]=1;
    for (int i=1;i<=30;i++) f[i]=f[i-1]*2;
    int k=s.length();
    if (m>k*f[n]){
        cout<<-1;
        return 0;
    }

    int i=n;
    while (i!=0)
    {
        long long t=k*f[i]/2;
        if (m>t)
            m=t*2-m+1;
        i--;
    }
    cout<<s[m-1];
}
