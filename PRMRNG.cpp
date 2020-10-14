/*https://bom.to/nxtvde2k1m4l*/
#include<bits/stdc++.h>
using namespace std;
#define task "PRMRNG"
#define write(a) printf("%d\n",a)
#define debug2(a,b) printf("%d %d\n",a,b)
#define debug3(a,b,c) printf("%d %d %d\n",a,b,c)
#define debug4(a,b,c,d) printf("%d %d %d %d\n",a,b,c,d)
typedef pair<int,int> ii;
const int N = 1e6+5;
int a,b,k,f[N];
void init()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
void sang()
{
    vector < int > a(N + 5,0);
    a[1] = 1;
    a[0] = 1;
    for (int i = 2; i <= trunc(sqrt(N)); i ++) {
        if (!a[i]) {
            int j = i + i;

            while (j <= N) {
                a[j] = 1;
                j += i;
            }
        }
    }
    for (int i = 1; i <= 1000000; i ++)
    if (!a[i]) f[i] = f[i-1] + 1;
    else f[i] = f[i-1];
}
bool check (int l)
{
    for (int x = a; x <= b - l + 1; x++ )
    if (f[x + l - 1] - f[x-1] < k) return false;

    return true;
}
int main()
{
    init();
    sang();
    scanf("%d%d%d",&a,&b,&k);

    int ans = -1;
    int l = 1, r = b - a + 1;
    while (l <= r) {
        int mid = (l + r ) / 2;

        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    printf("%d",ans);
}



