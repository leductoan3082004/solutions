#include<bits/stdc++.h>

using namespace std;

#define task "CHAIN2_iterator"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

struct trie
{
    trie *c[26];
    int dp;
    trie(){}
    trie(trie *child)
    {
        for (int i = 0; i < 26; ++i) child->c[i] = NULL;
        dp = 0;
    }
};
trie *root;
void add(string s)
{
    node *root = root;

    for (int i = 0; i < s.length(); ++i) {
        int c = s[i] - 'a';
        if (!)
    }
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    root = new trie(NULL);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s; cin >> s;
        add(s);
    }

    cout << ans;
}










