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

  vector<int> f(100 , 0);
  vector<int> w = {1, 5, 10, 20, 100};
  for (int i = 1; i <= 100; ++i) {
    for (int j = 0; j < w.size(); ++j) {
      if (i>=w[j] && (f[i] == 0 || f[i-w[j]]+1 < f[i]))
        f[i] = f[i-w[j]]+1;
    }
//    cout << f[i] << endl;
  }

  cout << (n/100 + f[n%100]) << endl;
}
