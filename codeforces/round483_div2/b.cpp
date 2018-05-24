/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int DX[] = {-1, 0, 1};
const int DY[] = {-1, 0, 1};

int tonumber(char c) {
  if (c == '.') return 0;
  if (c == '*') return -1;
  return c-'0';
}

int main() {
  vector<string> s;
  int n, m;
  cin >> n >> m;


  for (int i = 0; i < n; ++i) {
    string tmp;
    cin >> tmp;
    s.push_back(tmp);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int marker = tonumber(s[i][j]);
      if (marker == -1) continue;

      int mine_count = 0;
      for (int dx: DX)
        for (int dy: DY) {
          int x = i+dx, y = j+dy;
          if (x < 0 || y < 0 || x >= n || y >= m) continue;
          mine_count += (s[x][y]=='*');
        }

      if (mine_count != marker) {
        cout << "NO" << endl;
        return 0;
      }

    }
  }

  cout << "YES" << endl;
}
