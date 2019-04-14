#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
#define _for(iter, l, h) for (int iter = l; iter < h; iter++)
#define _forr(iter, h, l) for (int iter = h; iter > l; iter--)
typedef pair<ll, ll> p_ll;

/*-- templates --*/

int main() {
  accelerate_io();

  string s;
  cin >> s;
  int maxv = 0;
  for (int i = 0; i < s.size(); ++i) {
    for (int j = i; j < s.size(); ++j) {
      if (s[i] != s[j])
        maxv = max(maxv, j-i+1);
    }
  }

  cout << maxv << endl;
}


