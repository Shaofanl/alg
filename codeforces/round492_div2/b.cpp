/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
#define _for(iter, l, h) for (int iter = l; iter < h; iter++)
#define _forr(iter, h, l) for (int iter = h; iter > l; iter--)



int main() {
  int n;
  cin >> n;

  int minv = -1, minx = 0;
  for (int i = 0; i < n; ++i) {
    ll a_i;
    cin >> a_i;
    ll times = (a_i - (i+1) + n)/n;
    if (minv == -1 || minv > times) {
      minv = times;
      minx = i;
    }
  }
  cout << minx+1 << endl;
}
