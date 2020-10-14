#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define maxn 205
#define LT "brothers"
#define pb push_back
#define For( i , a , b ) for( int i = a ; i <= b ; i++ )
#define FOr( i , a , b ) for( int i = a ; i >= b ; i-- )
#define endl "\n"

int i,j,n,k,m;
int a[maxn][maxn];
ll f[maxn][maxn][2*maxn] , vc=1e15;

void nhap()
{
    freopen(LT".inp","r",stdin);
    freopen(LT".out","w",stdout);
    scanf("%d %d",&n,&m);
    For(i,1,n)
    {
        For(j,1,m)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void xuli()
{

    /// Ý nghĩa fijk : là số điểm lớn nhất nhận được sau k bước và người thứ nhất đứng lại ở hàng i và người thứ 2 đứng lại ở hàng j
    /// Vì ta biết số bước và hàng đi tới nên ta sẽ biết được cột mà nó sẽ tới là gì

    int j,jres;
    ll tam1,tam2,tam3,tam4;

    /// Khởi tạo cho bước đầu tiên
    f[1][2][1]=a[1][2]+a[2][1];

    for(int c=2;c<=m+n-3;c++)   /// Chun
    {
        for(int i=max(1,c-m+2);i<=min(c,n-1);i++)
        {
            for(int ires=max(2,c-m+1);ires<=min(c+1,n);ires++)
            {
                j=c-i+2;
                jres=c-ires+2;
                if( (i==ires && c!=n+m-2) || (i==2 && j==1) ) f[i][ires][c]=-vc;
                else
                {

                    if( i<=1 || ires<=2 || j<=1 || jres<=0) tam1=-vc;
                    else tam1=f[i-1][ires-1][c-1];

                    if( i<=1 || j<=1 || ires<=1 || jres<=1 ) tam2=-vc;
                    else tam2=f[i-1][ires][c-1];

                    if( i<=0 || j<=2 || ires<=2 || jres<=0 ) tam3=-vc;
                    else tam3=f[i][ires-1][c-1];

                    if( i<=0 || j<=2 || ires<=1 || jres<=1 ) tam4=-vc;
                    else tam4=f[i][ires][c-1];

                    f[i][ires][c]=max(max(tam1,tam2),max(tam3,tam4))+a[i][j]+a[ires][jres];
                }
            }
        }
    }
    printf("%lld",f[n-1][n][m+n-3]);
}
int main()
{
    nhap();
    xuli();
}
