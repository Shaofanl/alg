/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
#define _for(iter, l, h) for (int iter = l; iter < h; iter++)
#define _forr(iter, h, l) for (int iter = h; iter > l; iter--)
typedef pair<ll, ll> p_ll;


// use hash, not segment tree
// hash can shift with multiplying a power
// 
// idea:
//  use prefix hash to reduce the query time from O(n) to O(1)
// notice
//  handle the MOD (negative properly)


const ll MAXN = 200005;
const ll MOD = 998244353;
const ll SEED = 2333;
ll power[MAXN], hasht[26][MAXN];

int main() {
  ll n, m;
  cin >> n >> m;
  string s;
  cin >> s;

  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < n; ++j) {
      hasht[i][j] = (j>0?SEED * hasht[i][j-1]:0) + (s[j]-'a'==i);
      hasht[i][j] %= MOD;
      // hash is a <SEED>-based (e.g. 2333-based) 0-1 number
    }
  }

//_for(i, 0, 3) {
//  _for(j, 0, n)
//    cout << hasht[i][j] << "\t";
//  cout << endl;
//}

  // hash * power <=> shift: O(N) -> O(1)
  power[0] = 1;
  for (int i = 1; i < n; ++i) 
    power[i] = SEED * power[i-1] % MOD;

  // from len domain to char domain 
  //  O(len) to O(C)
  vector<ll> hasha(26, 0), hashb(26, 0);
  while (m--) {
    ll a, b, l;
    cin >> a >> b >> l;
    a--; b--;

    for (int i = 0; i < 26; ++i) {
      hasha[i] = hasht[i][a+l-1] - (a==0?0:power[l] * hasht[i][a-1]%MOD);
      hashb[i] = hasht[i][b+l-1] - (b==0?0:power[l] * hasht[i][b-1]%MOD);
      hasha[i] = (hasha[i]+MOD)%MOD;
      hashb[i] = (hashb[i]+MOD)%MOD;
    }

    sort(hasha.begin(), hasha.end());
    sort(hashb.begin(), hashb.end());

//  copy(hasha.begin(), hasha.end(), ostream_iterator<ll>(cout, ", ")); cout << endl;
//  copy(hashb.begin(), hashb.end(), ostream_iterator<ll>(cout, ", ")); cout << endl;

    bool flag = true;
    for (int i = 0; i < 26; i++)
      if (hasha[i] != hashb[i])
        flag = false;

    cout << (flag?"YES":"NO") << endl;
  }
}
