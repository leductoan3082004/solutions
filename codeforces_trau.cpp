#include <bits/stdc++.h>
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
*/

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;

/*
struct Node
{
	int node, len;
	Node() {node = len = 0;}
	Node(int node, int len) {this -> node = node, this -> len = len;}
};
typedef vector<Node> vg;
*/

#define MAX 1000001
#define MOD 1000000007

#define fi first
#define se second
#define pf push_front
#define pb push_back

#define FOR(type, i, a, b) for(type i = (a); i <= (b); i++)
#define FORR(type, i, b, a) for(type i = (b); i >= (a); i--)

#define testBit(n, bit) ((n >> bit) & 1)
#define flipBit(n, bit) (n ^ (1ll << bit))
#define cntBit(n) __builtin_popcount(n)
#define cntBitll(n) __builtin_popcountll(n)
#define randomize mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
#define task "codeforces"
int n;
int h[MAX], f[MAX] = {};
// int up[MAX] = {}, down[MAX] = {};
vi graph[MAX];
stack<int> st;

main()
{
    freopen(task".inp","r",stdin);
    freopen(task".ans","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n; FOR(int, i, 1, n) cin >> h[i];
	st.push(1);
	FOR(int, i, 2, n){
		int currH = h[i];
		bool same = false;
		while (!st.empty() && h[st.top()] >= currH) {
			int pos = st.top(); st.pop();
			if (same) continue;
			if (h[pos] == currH) same = true;
			// up[pos] = i;
			graph[pos].push_back(i);
		}
		if (!st.empty() && !same)
			graph[st.top()].push_back(i);
		st.push(i);
	}
	while (!st.empty()) st.pop();
	st.push(1);
	FOR(int, i, 2, n){
		int currH = h[i];
		bool same = false;
		while (!st.empty() && h[st.top()] <= currH) {
			int pos = st.top(); st.pop();
			if (same) continue;
			if (h[pos] == currH) same = true;
			// down[pos] = i;
			graph[pos].push_back(i);
		}
		if (!st.empty() && !same)
			graph[st.top()].push_back(i);
		st.push(i);
	}
	f[n] = 0;
	FORR(int, i, n - 1, 1){
		f[i] = f[i + 1] + 1;
		// cerr << "curr:" << i << ' ' << up[i] << ' ' << down[i] << '\n';
		for (int child: graph[i]){
			f[i] = min(f[i], f[child] + 1);
			// cerr << "//" << child << '\n';
		}
		// if (up[i]) f[i] = min(f[i], f[up[i]] + 1);
		// if (down[i]) f[i] = min(f[i], f[down[i]] + 1);
		// cerr << i << ' ' << up[i] << ' ' << down[i] << "-->" << f[i] << '\n';
	}
	cout << f[1];
}
