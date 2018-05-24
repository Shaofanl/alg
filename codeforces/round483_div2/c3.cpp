/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }

// do not have to traverse 1~q to find the common divisor
// can just use gcd

// mine original idea: find divisors in q
// the correct one: find common divisor in b and q
//   which takes less steps

const ll MAX = 20; // 1e18+2;

ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a%b);
}

bool check(ll q, ll b) {
  b = gcd(q, b);
  while (b != 1) {
    while (q % b == 0) q /= b;
    b = gcd(q, b);
  }
  return q==1;
}

int main() {
  accelerate_io();

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
