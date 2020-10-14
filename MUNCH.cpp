#include<bits/stdc++.h>
using namespace std;
const int N=1000, M=1000;
int ans[N][M],n,m,pos1,pos2;
int d1[10],d2[10];
vector<char>a[1000];
deque<int>r,c;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("MUNCH.inp","r",stdin);
    freopen("MUNCH.out","w",stdout);
    cin>>n>>m;
    d1[1]=0; d1[2]=-1; d1[3]=1; d1[4]=0;
    d2[1]=1; d2[2]=0; d2[3]=0; d2[4]=-1;
    for (int i=1; i<=n; i++){
        a[i].push_back('l');
        for (int j=1; j<=m; j++){
            char x;
            cin>>x;
            a[i].push_back(x);
            if (a[i][j]=='C'){
                pos1=i;
                pos2=j;
            }
        }
    }
    ans[pos1][pos2]=1;
    r.push_back(pos1);
    c.push_back(pos2);
    while (!r.empty()&&!c.empty()){
        int i1=r.front();
        int j1=c.front();
        r.pop_front();
        c.pop_front();
        for (int k=1; k<=4; k++){
            int i=i1+d1[k];
            int j=j1+d2[k];
            if (i>=1&&i<=n&&j>=1&&j<=m){
                if (a[i][j]=='*') continue;
                if (ans[i][j]>0) continue;
                r.push_back(i);
                c.push_back(j);
                //cout<<1;
                ans[i][j]=ans[i1][j1]+1;
            }

        }
    }
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        if (a[i][j]=='B'){
            cout<<ans[i][j]-1;
            break;
        }
}

