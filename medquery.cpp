#include<bits/stdc++.h>
using namespace std;
#define task "medquery"
#define lwb lower_bound
#define upb upper_bound
#define ar array
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
template <typename T>
inline void read(T& x)
{
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' | c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}
void solve()
{
    int q;
    read(q);
    multiset<int,greater<int> > s1;
    multiset<int> s2;
    for(int _=1;_<=q;++_)
    {
        char c; int x;
        c=getchar();
        read(x);
        if(c=='+') s2.insert(x);
        else
        {
            if(s1.find(x)!=s1.end()) s1.erase(s1.find(x));
            else if(s2.find(x)!=s2.end()) s2.erase(s2.find(x));
        }
        int sz1=s1.size(), sz2=s2.size();
        while(s1.size()<s2.size())
        {
            s1.insert(*s2.begin());
            s2.erase(s2.begin());
        }
        while(s1.size()>s2.size()+1)
        {
            s2.insert(*s1.begin());
            s1.erase(s1.begin());
        }
        while(s1.size()&&s2.size()&&*s1.begin()>*s2.begin())
        {
            int it1=*s1.begin();
            int it2=*s2.begin();
            s1.erase(s1.begin());
            s2.erase(s2.begin());
            s1.insert(it2);
            s2.insert(it1);
        }

        write(*s1.begin()); putchar('\n');
    }
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
