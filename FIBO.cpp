#include <bits/stdc++.h>
using namespace std;
struct matrix
{
    int d[2][2];
};

long long n,t;
matrix base={0,1,1,1};
matrix maXma(matrix a,matrix b)
{
    matrix kq={0,0,0,0};
    for (int i=0;i<=1;i++)
    for (int j=0;j<=1;j++)
    for (int k=0;k<=1;k++) kq.d[i][j]=(kq.d[i][j]+1ll*a.d[i][k]*b.d[k][j])%t;
    return kq;
}

matrix nekan(long long x)
{
    if (x==1) return base;
    matrix res=nekan(x/2);
    res=maXma(res,res);
    if (x%2==1) res=maXma(res,base);
    return res;
}
long long fib(int n)
{
    matrix kq=nekan(n);
    cout<< kq.d[0][1] << '\n' ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("FIBO1295.inp","r",stdin);
    freopen("FIBO1295.out","w",stdout);
    int q;
    cin>>q;
    while (q--)
    {
        cin>>n;
        t=1e9+7;
        matrix kq=nekan(n);
        cout<< kq.d[0][1] << '\n' ;
    }
}