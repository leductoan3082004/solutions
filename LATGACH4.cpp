/*https://bom.to/nxtvde2k1m4l*/
#include<bits/stdc++.h>
using namespace std;
#define task "LATGACH4"
#define debug cout << '\n';
typedef pair<int,int> ii;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
struct matrix
{
    int d[2][2];
};

long long n,t = 111539786;
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
    return kq.d[0][1];
}
int main()
{
    init();
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        n++;
        cout << fib(n) << '\n';
    }
}

