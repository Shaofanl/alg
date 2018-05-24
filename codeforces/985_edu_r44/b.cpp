/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
#define _for(iter, l, h) for (int iter = l; iter < h; iter++)
#define _forr(iter, h, l) for (int iter = h; iter > l; iter--)


int a[2001][2001];
int sum[2001];

int main() {
  accelerate_io();

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      a[i][j] = s[j] == '1';
      sum[j] += a[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    bool flag = true;
    for (int j = 0; j < m; ++j)
      if (sum[j] - a[i][j] <= 0) {
        flag = false;
        break;
      }
    if (flag) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}
