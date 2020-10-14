#include <bits/stdc++.h>
using namespace std;
string a,b;
int f[1000][1000];
int main()
{
    freopen("QBSTR.inp","r",stdin);
    freopen("QBSTR.ans","w",stdout);
    getline(cin,a);
    getline(cin,b);
    a='a'+a;
    b='a'+b;
    for (int i=1; i<a.length();i++)
    {
        for (int j=1; j<b.length(); j++)
        {
            if (a[i]==b[j])
            {
                f[i][j]=f[i-1][j-1]+1;
            }
            else
            {
                f[i][j]=max(f[i-1][j],f[i][j-1]);
            }
        }
    }
    cout<<f[a.length()-1][b.length()-1];
}

