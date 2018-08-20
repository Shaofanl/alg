/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
#define _for(iter, l, h) for (int iter = l; iter < h; iter++)
#define _forr(iter, h, l) for (int iter = h; iter > l; iter--)
/*-- templates --*/

inline double f(int i, int j) {
  return double(j)/double(i);
}


int main() {
  accelerate_io();

  int T;
  cin >> T;
  while (T--) {
    int n, temp;
    cin >> n;

    unordered_set<int> set;
    vector<int> a;

    for (int i = 0; i < n; ++i) {
      cin >> temp;
      if (set.find(temp) != set.end()) {
        a.push_back(temp);
        set.erase(temp);
      }
      else
        set.insert(temp);
    }

    sort(a.begin(), a.end());

    if (a.size() == 2) {
      cout << a[0] << ' ' << a[0] << ' ' << a[1] << ' ' << a[1] << endl;
      continue;
    }

    double mint = -1;
    int mini, minj;
    for (int i = 0; i <= a.size()-2; ++i) {
      if (mint < 0 || mint > f(a[i], a[i+1])) {
        mint = f(a[i], a[i+1]);
        mini = a[i];
        minj = a[i+1];
      }
    }
    cout << mini << " " << mini << " " << minj << " " << minj << endl;
  }
}
