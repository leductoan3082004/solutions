#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define LT "rect"
#define maxn 305
#define endl "\n"
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i-- )

int i,j,n,m,k;
int a[maxn][maxn] , Min[maxn][maxn] , vc = 1e9 ;
int d[maxn][maxn];

void nhap()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(LT".inp","r",stdin);
    freopen(LT".out","w",stdout);
    cin >> n >> m;
    For( i , 1 , n ) For( j , 1 , m ) cin >> a[i][j];
}

void process()
{
    For( i , 1 , n )
    {
        Min[i][m+1] = m+1;
        FOr( j , m , 1 )
        {
            if( a[i][j] ) Min[i][j] = j;
            else Min[i][j] = Min[i][j+1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cout << Min[i][j] << ' ';
        cout <<endl;
    }
}

void xuli()
{
    process();

    For( i , 1 , n )
    {
        For( j , 1 , m )
        {
            int minn = vc;
            For( ires , i , n )
            {
                minn = min ( minn , Min[ires][j] );
                if( minn == j ) break;
                d[ires-i+1][minn-j]++;
            }
        }
    }

    For( i , 1 , n )
    {
        FOr( j , m , 1 )
        {
            d[i][j] = d[i][j] + d[i][j+1];
        }
    }

    For( i , 1 , n )
    {
        For( j , 1 , m )
        {
            cout << d[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    nhap();
    xuli();
}
