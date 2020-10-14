/* NTD214 */
#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define cl cout<<endl
#define For(i,a,b) for (int i=a; i<=b; i++)
#define Forr(i,a,b) for (int i=a; i<b; i++)
#define Refor(i,a,b) for (int i=a; i>=b; i--)
#define Reforr(i,a,b) for (int i=a; i>b; i--)
#define pb push_back
#define vi vector<int>
#define _io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PROB "SUDI"
using namespace std;
const int N=4*100005;
ll Deque_min[N],Deque_max[N],a[N],top=0,rear=0,n;
ull ans,sum_max,sum_min;
void init()
{
    freopen(PROB".inp","r",stdin);
    freopen(PROB".out","w",stdout);
}
void readdata()
{
    cin>>n;
    For(i,1,n) scanf("%lld",&a[i]);
}
void solve()
{
    For(i,1,n)
    {
        while(a[Deque_min[top]]>a[i]&&top>0)
        {
            sum_min-=a[Deque_min[top]]*(Deque_min[top]-Deque_min[top-1]);
            top--;
        }
        Deque_min[++top]=i;
        sum_min+=(Deque_min[top]-Deque_min[top-1])*a[i];
        while(a[Deque_max[rear]]<a[i]&&rear>0)
        {
            sum_max-=a[Deque_max[rear]]*(Deque_max[rear]-Deque_max[rear-1]);
            rear--;
        }
        Deque_max[++rear]=i;
        sum_max+=(Deque_max[rear]-Deque_max[rear-1])*a[i];
        //cout<<sum_max<<endl;
        ans+=sum_max-sum_min;
    }
    cout<<ans;
}
int main()
{
    init();
    readdata();
    solve();
}
