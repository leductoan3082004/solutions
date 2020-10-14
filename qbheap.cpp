#include<bits/stdc++.h>

using namespace std;

#define task "qbheap"
#define fi first
#define se second
#define fore(i,a,b) for(int i=(int)a;i<=(int)b;++i)
#define ford(i,a,b) for(int i=(int)a;i>=(int)b;--i)

typedef long long ll;
typedef pair<int,int> pii;

void solve()
{
    multiset<int,greater<int>> s;
//    cout<<s.empty()<<'\n';
    while(1)
    {
        char ch='u';
        cin>>ch;
        cout<<ch<<'\n';
        if(ch=='u') break;
        if(ch=='-'&&!s.empty())
        {
            int val=*s.begin();
            s.erase(val);
        }
        else
        {
            int val; cin>>val;
            if(s.size()<=15000) s.insert(val);
        }
    }
//    cout<<s.empty()<<'\n';
//    vector<int>a;
//    cout<<s.size()<<'\n';
//    for(auto it=s.begin();it!=s.end();++it) a.push_back(*it);
//    a.resize(unique(a.begin(),a.end())-a.begin());
//
//    cout<<a.size()<<'\n';
//    for(int i:a) cout<<i<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    solve();
}






