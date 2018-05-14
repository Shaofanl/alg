// summary:
//    should use greedy on the correct direction
//    early or over-strict greedy might cause error
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> g(259, -1);
  vector<bool> took(258, false);
  vector<int> ans;

  g[0] = 0;
  while (n--) {
    int t;
    cin >> t;

    int ptr = t;
    while (ptr>=1 && !took[ptr]) ptr--;
    ptr = g[ptr];

    if (t-ptr+1>k) {
      ptr = t;
      while (ptr>=1 && !took[ptr-1] && t-ptr+1<k)
        ptr--;
    }

    for (int i = ptr; i <= t; ++i) {
      took[i] = true;
      g[i] = ptr;
    }

    cout << g[t] << ' ';
  }
  cout << endl;
}
