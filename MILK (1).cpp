#include <bits/stdc++.h>
using namespace std;
long long n,m,k,l=0,a[1000001],b[1000001],kq=0;
void xuli()
{
    queue <long long> q,p;
    for(int i=1;i<=n;i++)
        q.push(a[i]);
    for(int i=1;i<=m;i++)
        p.push(b[i]);

    while(q.size()>0)
    {
        if(q.front()<l) {cout<<-1; return;}
        long tmp=k;
        while(p.front()<l&&p.size()>0)
            p.pop();
        if(q.front()>=l)
        {
            while(tmp>0)
            {
                if(q.size()==0) break;
                if(p.size()>0&&p.front()<q.front()) {p.pop(); kq++; tmp--;}
                else {q.pop(); tmp--;}
            }
        }
        l++;
    }

    while(p.size()>0)
    {
        while(p.size()>0&&p.front()<l) p.pop();
        long tmp=k;
        while(tmp>0&&p.size()>0)
        {
            p.pop();
            tmp--;
            kq++;
        }
        l++;
    }
    cout<<kq;
}
int main()
{
    //freopen("MILK.inp", "a+",stdin);
    //freopen("MILK.out", "w+",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=m;i++)
        cin>>b[i];
    sort(b+1,b+m+1);
    xuli();
}
