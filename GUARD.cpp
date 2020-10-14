#include<bits/stdc++.h>
using namespace std;
int a[1005][1005],ans,n,m;
bool visited[1005][1005];
queue<int>h,c;
bool bfs(int i1, int j1){
    h.push(i1);
    int res=1;
    c.push(j1);
    int H=a[i1][j1];
    while (!h.empty()){
        int i=h.front();
        int j=c.front();
        h.pop(); c.pop();
        for (int x=-1; x<=1; x++)
        for (int y=-1; y<=1; y++){
            int xx=x+i,yy=y+j;
                if (H<a[xx][yy])  res=0;
                else
                if ((visited[xx][yy]==false)&&a[xx][yy]==H){
                    visited[xx][yy]=true;
                    h.push(xx);
                    c.push(yy);
                }
        }
    }
    return res;

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("GUARD.inp","r",stdin);
    freopen("GUARD.out","w",stdout);
    cin>>n>>m;
     for (int i=0; i<=n+1; i++)
        for (int j=0; j<=m+1; j++) a[i][j]=-1;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) cin>>a[i][j];
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++){
        if (!visited[i][j]&&a[i][j]!=0) ans+=bfs(i,j);
    }
    cout<<ans;
}
