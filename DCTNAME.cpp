/*https://bom.to/nxtvde2k1m4l*/
#include<bits/stdc++.h>
using namespace std;
#define task "DCTNAME"
#define debug cout << '\n';
typedef pair<int,int> ii;
void init()

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
vector<int > a[30],b[30];
int main()
{
    init();
    string s1,s2;
    cin >> s1 >> s2;
    for (int i = 0 ; i < s1.length() ; i++)
    a[s1[i] - 'a'].push_back(i);

    for (int i = 0 ; i < s2.length(); i++)
    b[s2[i] - 'a'].push_back(i);
    string ans = "";
    int apos = -1, bpos = -1;
    for (int  ch = 'z'; ch >= 'a'; ch--){
        int k = ch - 'a';
        if (a[k].size() == 0 || b[k].size() == 0) continue;
        while (1) {
            int new_apos = upper_bound(a[k].begin(),a[k].end(),apos) - a[k].begin();
            int new_bpos = upper_bound(b[k].begin(),b[k].end(),bpos) - b[k].begin();
            if (new_apos == a[k].size()) break;
            if (new_bpos == b[k].size()) break;
            new_apos = a[k][new_apos];
            new_bpos = b[k][new_bpos];
            apos = new_apos;
            bpos = new_bpos;

            ans = ans + s1[apos];
        }
    }
    cout << ans ;
}

