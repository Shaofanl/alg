/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
#define _for(iter, l, h) for (int iter = l; iter < h; iter++)
#define _forr(iter, h, l) for (int iter = h; iter > l; iter--)

typedef pair<double, double> pdd;

double inline norm(double x, double y) {
  return sqrt((x*x)+(y*y));
}

double norm(pdd v) {
  return norm(v.first, v.second);
}

int main() {
  int n;
  cin >> n;

  vector<pdd> a;
  for (int i = 0; i < n; ++i) {
    double dx, dy;
    cin >> dx >> dy;
    a.push_back(make_pair(dx, dy));
  }

  double x = 0, y = 0;
  sort(a.begin(), a.end(),
      [](const pdd &left, const pdd &right) {
        return norm(left) > norm(right);
      });

  for (int i = 0; i < n; ++ i) {
    // cout << a[i].first << ", " << a[i].second << endl;
    if (norm(x+a[i].first, y+a[i].second) <= norm(x-a[i].first, y-a[i].second)) {
      x += a[i].first;
      y += a[i].second;
      cout << "1 ";
    }
    else {
      x -= a[i].first;
      y -= a[i].second;
      cout << "-1 ";
    }
  }
}
