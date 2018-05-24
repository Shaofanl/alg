/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// failed: prime takes too long
// wrong! prime table can itself be small

const ll MAX = 20; // 1e18+2;

ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a%b);
}

bool check(ll q, ll base) {
  while (q != 1) {
    for (ll i = 2; i <= q; ++i)
      if (q % i == 0) {
        if (base % i != 0) return false;
        while (base % i == 0) base /= i;
        while (q % i == 0) q /= i;
      }
  }
  return true;
}

vector<ll> prime;
bool skip[MAX] = {0};

int main() {
  long long cnt = 0;
  for (ll i = 2; i < MAX && cnt < MAX; ++i)
    if (!skip[i]) {
      prime.push_back(i);
      for (int j = i; j < MAX; j += i)
        if (!skip[j]) {
          skip[j] = true;
          cnt++;
        }
      cout << "I " << i << " CNT " << cnt << endl << flush;
    }
  cout << "Here" << endl;

  int T;
  cin >> T;
  while (T--) {
    ll p, q, b;
    cin >> p >> q >> b;

    ll gcdv = gcd(p, q);
    p /= gcdv;
    q /= gcdv;

    cout << ((check(q, b))?"Finite":"Infinite") << endl;
  }
}
