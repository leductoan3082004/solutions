#include <bits/stdc++.h>
using namespace std;
string a,b;
int m,n;
void fi()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("lock1043.inp","r",stdin);
    freopen("lock1043.out","w",stdout);
}
void inp()
{
    cin>>n;
    cin>>a;
    cin>>m;
    cin>>b;

}
void one()
{
    for (int i=0;i<=a.length()-1;i++)
    {
        if (a[i]=='1') a[i]='2';
        else if (a[i]=='2') a[i]='3';
        else if (a[i]=='3') a[i]='4';
        else if (a[i]=='4') a[i]='5';
        else if (a[i]=='5') a[i]='6';
        else if (a[i]=='6') a[i]='7';
        else if (a[i]=='7') a[i]='8';
        else if (a[i]=='8') a[i]='9';
        else if (a[i]=='9') a[i]='0';
        else if (a[i]=='0') a[i]='1';
    }
}
void two()
{
    a[n]=a[n-1];
    for (int i=a.length()-2;i>=0;i--)
    {
        a[i+1]=a[i];
    }
    a[0]=a[n];
}
void solve()
{
    for (int i=0;i<=m;i++)
    {
        if (b[i]=='1')
        {
            one();
        }
        if (b[i]=='2')
        {
            two();
        }
    }
    cout<<a;
}
int main()
{
    fi();
    inp();
    solve();

}
