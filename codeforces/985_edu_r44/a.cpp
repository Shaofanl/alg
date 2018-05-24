/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
#define _for(iter, l, h) for (int iter = l; iter < h; iter++)
#define _forr(iter, h, l) for (int iter = h; iter > l; iter--)


int main() {
  vector<int> a;
  int n;
  cin >> n;

  copy_n(istream_iterator<int>(cin), n/2, back_inserter(a));
  sort(a.begin(), a.end());

  ll even = 0, odd = 0;
  for (int i = 1 ; i <= n/2; ++i) {
    even += abs(a[i-1]-2*i);
    odd += abs(a[i-1]-(2*i-1));
  }
  cout << min(odd, even) << endl;
}
