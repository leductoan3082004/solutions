#include <bits/stdc++.h>
using namespace std;

void fi()
{
    freopen("milk.inp","a+",stdin);
    freopen("milk.out","w+",stdout);
}

struct milk{
    int exp;
    int pla;
};
typedef struct milk milk;
milk a[2000001];

int n,m,k;

void input()
{
    cin>>n>>m>>k;
    for ( int i=1;i<=n;i++)
    {
        cin>>a[i].exp;
        a[i].pla=1;
    }
    for (int i=n+1;i<=n+m;i++)
    {
        cin>>a[i].exp;
        a[i].pla=2;
    }

}

bool cmp(milk a,milk b)
{
    if (a.exp==b.exp)
        return a.pla<b.pla;
    else
        return a.exp<b.exp;
}

void output()
{
    sort(a+1,a+1+n+m,cmp);
    int kq=0,day=0,shs=0;
    for (int i=1;i<=n+m;i++)
    {
        if (a[i].exp<day )
        {
            if (a[i].pla==1) {cout<<-1;return;}
            else continue;
        }
        shs++;
        if (a[i].pla==2) kq+=1;
        if (shs==k) {shs=0;day+=1;}
    }
    cout<<kq;

}

int main()
{
    //fi();
    input();
    output();
    return 0;
}
