#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define FOr(i,a,b) for(int i=a;i>=b;i--)
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
const int mm=2e5+5,oo=2e9-1;
int n,m,k;
int a[mm],f[mm][3];
int main()
{
    scanf("%d %d %d",&m,&n,&k);
    int vt=-k;
    For(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    f[1][1]=k; f[1][2]=k;
    For(i,2,n)
    {
        int mi=oo,mi1=oo;
        mi1=min(mi1,f[i-1][2]+k);
        if(a[i]-a[i-1]<k) mi1=min(mi1,f[i-1][1]+a[i]-a[i-1]);
        For(j,1,i-1)
        {
            if(a[i]-a[j]<k-1) mi=min(mi,min(f[j][1]+a[j]-a[i]+k,f[j][2]+a[i]-a[j]+1));
            else
            {
                if(a[i]-a[j+1]<=k-1) mi=min(mi,f[j][2]+k);
                if(a[i]-a[j]<2*k-1) mi=min(mi,f[j][1]+a[i]-a[j]-k+1);
            }
        }
        f[i][2]=mi; f[i][1]=mi1;
    }
    printf("%d",f[n][2]);
}
