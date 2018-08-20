/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
#define _for(iter, l, h) for (int iter = l; iter < h; iter++)
#define _forr(iter, h, l) for (int iter = h; iter > l; iter--)
/*-- templates --*/


bool check(string s) {
  int i = 0, j = s.size()-1;
  while (i < j) {
    int diff = abs(s[i++]-s[j--]);
    if (diff != 2 && diff != 0) return false;
  }
  return true;
}

int main() {
  accelerate_io();

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << (check(s)?"YES":"NO") << endl;
  }
}
