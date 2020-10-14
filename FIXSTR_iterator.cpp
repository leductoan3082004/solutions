#include<bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cout << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define task "FIXSTR"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

struct node
{
    int L , R;
    node *left, *right;
    node(){}
    node(int valL, int valR, node *l, node *r)
    {
        left = l;
        right = r;
        L = valL;
        R = valR;
    }
};

const int N = 1e6 + 5;
node *version[N];
int n;
string s;

void build(node *cur, int l, int r)
{
    if (l == r) {
        if (s[l] == '(') cur->L = 1;
        else cur->R = 1;
        return;
    }
    cur->left = new node(0,0,NULL,NULL);
    cur->right = new node(0,0,NULL,NULL);

    int mid = (l + r) >> 1;
    build(cur->left,l,mid);
    build(cur->right, mid + 1, r);
    node *a = cur->left;
    node *b = cur->right;
    int mn = min(a->L,b->R);
    int L = a->L - mn + b->L;
    int R = b->R - mn + a->R;
    cur->L = L;
    cur->R = R;
}
void update(node *cur,node *pre, int l, int r, int pos)
{
    if (l == r) {
        if (s[l] == '(') {
            cur->L = 1;
            cur->R = 0;
        }
        else {
            cur->R = 1;
            cur->L = 0;
        }
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) {
        cur->left = new node(0,0,NULL,NULL);
        cur->right = pre->right;
        update(cur->left,pre->left,l,mid,pos);
    }
    else {
        cur->right = new node(0,0,NULL,NULL);
        cur->left = pre->left;
        update(cur->right,pre->right,mid + 1, r , pos);
    }
    node *a = cur->left;
    node *b = cur->right;
    int mn = min(a->L,b->R);
    int L = a->L - mn + b->L;
    int R = b->R - mn + a->R;
    cur->L = L;
    cur->R = R;
}
int dem = 0;
pair<int,int> get(node *cur, int l, int r, int u, int v)
{
    if (u > r || v < l) return {0,0};
    if (u <= l && r <= v) {
        return {cur->L,cur->R};
    }
    int mid = (l + r) >> 1;
    pair<int,int> L = get(cur->left, l, mid, u, v);
    pair<int,int> R = get(cur->right, mid + 1, r, u , v);
    int mn = min(L.first,R.second);
    pair<int,int> ans = {L.first - mn + R.first, L.second + R.second - mn};
    return ans;
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".ans","w",stdout);

    cin >> s;
    n = s.length();
    s = ' ' + s;
    version[0] = new node(0,0,NULL,NULL);
    build(version[0],1,n);
    int q; cin >> q;
    int ver = 0;
    for (int i = 1 ; i <= q; ++i){
        ++ver;
        version[ver] = new node(0,0,NULL,NULL);
        version[ver] = version[ver - 1];
        char t; cin >> t;
        if (t == 'C') {
            int pos; cin >> pos;
            if (s[pos] == '(') s[pos] = ')';
            else s[pos] = '(';
            version[ver] = new node(0,0,NULL,NULL);
            update(version[ver],version[ver-1],1,n,pos);
        }
        if (t == 'Q') {
            int l, r;
            cin >> l >> r;
            pair<int,int> ans = get(version[ver],1,n,l,r);
            cout << ans.first + ans.second << '\n';
        }
        if (t == 'U') {
            int k; cin >> k;
            version[ver] = version[k - 1];
        }
    }

}









