/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
#define _for(iter, l, h) for (int iter = l; iter < h; iter++)
#define _forr(iter, h, l) for (int iter = h; iter > l; iter--)

// DP:
// if it's too hard to derive the recurrent formula
//    try to rethink the recurrent characteristic of the original problem 

const ll MAX = 5000;
ll f[MAX][MAX] = {0};

int main() {
  accelerate_io();

  int n;
  cin >> n;
  vector<int> a;

  copy_n(istream_iterator<int>(cin), n, back_inserter(a));

  _for(i, 0, n) {
    _for(j, 0, n)
      f[i][j] = -1;
    f[0][i] = a[i];
  }

  _for(i, 1, n)
    _for (j, 0, n-i)
      f[i][j] = f[i-1][j] ^ f[i-1][j+1];
//  _for(i, 0, n) { _for(j, 0, n) cout << f[i][j] << " "; cout << endl; }


  _for(i, 1, n)
    _for (j, 0, n-i)
      f[i][j] = max(f[i][j], max(f[i-1][j], f[i-1][j+1]));
//  _for(i, 0, n) { _for(j, 0, n) cout << f[i][j] << " "; cout << endl; }

  cin >> n;
  while (n--) {
    int l, r;
    cin >> l >> r; l--; r--;
//     cout << r-l+1 << ' ' << l << endl;
    cout << f[r-l][l] << endl;
  }


  // std::copy_n(istream_iterator<int>(cin), n, back_inserter(a));
  // std::copy(a.begin(), a.end(), ostream_iterator<int>(cout, ", "));

}
