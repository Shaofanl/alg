/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll MAX = 1e18+2;

ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a%b);
}

bool appeared[MAX];

bool check(ll p, ll q, ll b) {
  while (p) {
    p = p * b;
    // might overflow
    // TOOD
  }
  return true;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    ll p, q, b;
    cin >> p >> q >> b;

    ll gcdv = gcd(p, q);
    p /= gcdv;
    q /= gcdv;

    while (p > q) { p -= q; }
    if (p == 0) {
      cout << "Finite" << endl;
      continue;
    }

    // cout << p << ' ' << q << endl;

    cout << ((check(p, q, b))?"Finite":"Infinite") << endl;
  }
}
