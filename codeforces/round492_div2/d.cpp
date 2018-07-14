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

  vector<int> a;
  copy_n(istream_iterator<int>(cin), 2*n, back_inserter(a));

  ll cost = 0;
  for (int i = 0; i < 2*n; i+=2) {
    int key = a[i];
    int next_pos = i+1;
    while (a[next_pos] != key)
      ++next_pos;

    cost += (next_pos-(i+1));

    while (next_pos > i+1) {
      swap(a[next_pos], a[next_pos-1]);
      next_pos--;
    }

//  copy(a.begin(), a.end(), ostream_iterator<int>(cout, ", "));
//  cout << endl;
  }
  cout << cost << endl;
}
