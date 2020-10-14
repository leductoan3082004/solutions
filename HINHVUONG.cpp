#include <bits/stdc++.h>
using namespace std;
long long x;
vector <long long> ans,anss;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("HINHVUONG.inp","r",stdin);
    freopen("HINHVUONG.out","w",stdout);
    cin>>x;
    for (long long i=1;i<=5e6;i++)
    {
        long long S=x*6+i*i*i-i;
        long long I=i*i+i;
        I=I*3;
        long long k=S/I;
        if (i>k) break;
        if (S%I==0) {ans.push_back(i);anss.push_back(k);};
    }
    cout<<ans.size()*2<<'\n';
    for (int i=0;i<ans.size();i++) cout<<ans[i]<<" "<<anss[i]<<'\n';
    for (int i=ans.size()-1;i>=0;i--) cout<<anss[i]<<" "<<ans[i]<<'\n';
}
