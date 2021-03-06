// After simplifying the number, we can use O(1) to check pair
// 1. create a prime table first
// 2. ispair() is redundant, can simplify the computation first
// 3. special case for a[j] == 0
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

const int MAXN = 5005;
bool f[MAXN][MAXN] = {};
int counted[MAXN] = {0};
int tag[MAXN] = {};
int ans[MAXN] = {0};

typedef long long ll;

int count(ll & n, ll c) {
  int cc = 0;
  while (n % c == 0) {
    n /= c;
    cc++;
  }
  return cc;
}

vector<int> pset;
const int P = 1e5;
bool np[P] = {false};


bool ispair(ll u, ll v) {
  return (u==v);
  if (u == 0 || v == 0) return true;
  if (u == 1 && v == 1) return true;
  if (u == 1 || v == 1) return false;
  if (u > 0 && v < 0) return false;
  if (u < 0 && v > 0) return false;

  if (u < 0) u = -u;
  if (v < 0) v = -v;

  ll bound = ceil(sqrt(u)*sqrt(v));

  for (int i = 0; i < pset.size(); ++i) {
    if ((count(u, pset[i])+count(v, pset[i]))%2 != 0)
      return false;
    if (pset[i] > bound) break;
  }
  if (u > 1 || v > 1) return false;

  return true;
}

int main() {
  for (int i = 2; i < P; i++) 
    if (!np[i]) {
      pset.push_back(i);
      for (int j = i; j < P; j += i)
        np[j] = true;
    }


  ll n, tmp;
  cin >> n;
  vector<ll> a;

  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    bool flag = tmp < 0;
    if (flag) tmp = -tmp;

    for (int j = 0; j < pset.size(); ++j) {
      ll k = pset[j];
      if (k*k > tmp) break;
      while (tmp % (k*k) == 0)
        tmp /= (k*k);
    }
    if (flag) tmp = -tmp;
//  cout << tmp << " ";
    a.push_back(tmp);
  }

  for (int i = 0; i < n; ++i)
    for (int j = i; j < n; ++j) {
        f[i][j] = f[j][i] = ispair(a[i], a[j]);
//        cout << a[i] << " " << a[j] << endl;
//        cout << f[i][j] << endl;
    }

  for (int i = 0; i < n; ++i)
    tag[i] = i;
  for (int i = 0; i < n; ++i)
    if (tag[i] == i)
      for (int j = i+1; j < n; ++j)
        if (f[i][j])
          tag[j] = i;

//for (int i = 0; i < n; ++i)
//  cout << tag[i] << ' ';
//cout << endl;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      counted[j] = 0;
      
    int length = 0;
    for (int j = i; j < n; ++j) {
      if (a[j]!=0) {
        counted[tag[j]]++;
        if (counted[tag[j]] == 1) {
          length++;
        }
      }
//    if (a[j]!=0 && !counted[tag[j]]) {
//      counted[tag[j]] = true;
//      length++;
//    }
      ans[max(1, length)]++;
    }
  }

  for (int i = 1; i <= n; ++i)
    cout << ans[i] << ' ';

}
