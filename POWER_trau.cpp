#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FOD(i,a,b) for(int i=a; i>=b; i--)
#define pa pair<int,int>
#define fi first
#define se second
#define LL long long
#define MOD 100

using namespace std;
int n,k;
int A[100005],lcm;
int P[100005];
int K[10005][105];
int F[105];
int T[105];
LL ans = 1;
void eratos()
{
    FOR(i,2,sqrt(100))
    if(P[i]==0)
    FOR(j,2,100/i)
    if(P[j*i]==0)
    P[j*i] = i;
    FOR(i,1,100)
    if(P[i]==0) P[i] = i;
}
int main()
{
    freopen("POWER.inp","r",stdin);
    freopen("POWER.ans","w",stdout);
    eratos();
    cin >> n >> k;
    FOR(i,1,n) cin >> A[i];
    FOR(i,1,n)
    {
        int x = A[i];
        while(P[x]!=1)
        {
            K[i][P[x]]++;
            x = x/P[x];
        }
    }
    FOR(i,1,100)
    FOR(j,1,n)
    F[i] = max ( F[i] , K[j][i]);
    FOR(i,1,100)
    if(F[i])
    {
        FOR(j,1,100)
        if(j*k>=F[i])
        {
            T[i] = j;
            break;
        }
    }
    FOR(i,1,100)
    if(T[i])
    {
        LL z = i;
        FOR(j,1,T[i]) ans = ans * z;
    }
    cout << ans;
	return 0;
}
