#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
#define _for(iter, l, h) for (int iter = l; iter < h; iter++)
#define _forr(iter, h, l) for (int iter = h; iter > l; iter--)
typedef pair<ll, ll> p_ll;

/*-- templates --*/

map<ll, ll> ma;

int main() {
  accelerate_io();

  int n;
  ll a, x;
  cin >> n;
  while (n--) {
    cin >> a >> x;
    
    if (ma.find(a) == ma.end())
      ma[a] = x;
    else
      ma[a] = max(ma[a], x);
  }

  cin >> n;
  while (n--) {
    cin >> a >> x;
    
    if (ma.find(a) == ma.end())
      ma[a] = x;
    else
      ma[a] = max(ma[a], x);
  }

  ll ans = 0;
  for (auto it = ma.begin(); it != ma.end(); ++it)
    ans += it->second;
  cout << ans << endl;
}
