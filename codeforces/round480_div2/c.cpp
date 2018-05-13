#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> g(259, -1);
  vector<bool> took(258, false);
  vector<int> ans;
  while (n--) {
    int t; 
    cin >> t;

    int ptr = t;
    if (g[ptr] == -1) {
      while (ptr-1 >= 0 && (t-ptr+1<k) && (g[ptr-1] == -1 || !took[ptr-1])) {
				ptr--;
      }
			// cout << t << ">" << ptr << endl;

      for (int i = ptr; i <= ptr+k-1 && i <= 257; ++i) {
				if (took[i]) break;
				g[i] = ptr;
			}

			// for (int i = 0; i <= 10; ++i)
		//		cout << g[i] << ' ';cout <<endl;
    }
    ans.push_back(g[t]);
		took[t] = true;
  }
  for (auto x: ans)
    cout << x << ' ';
  cout << endl;
}