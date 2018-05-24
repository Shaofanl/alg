/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
#define _for(iter, l, h) for (int iter = l; iter < h; iter++)
#define _forr(iter, h, l) for (int iter = h; iter > l; iter--)

int main() {
  accelerate_io();

  ll n, k, limit;
  cin >> n >> k >> limit;
  vector<ll> a;
  copy_n(istream_iterator<ll>(cin), n*k, back_inserter(a));
  sort(a.begin(), a.end());

  
  int ptr = 0;
  while (ptr < n*k-1 && a[ptr+1]-a[0] <= limit)
    ptr ++;
  if (ptr+1<n) { cout << 0; return 0; }

//  cout << ptr << endl;
  ll s = 0;
  int str = 0;
  bool compact = false;
  for (int i = 0; i < n; ++i) {
//    cout << a[str] << ' ';
    s += a[str];
    if (compact) {
      str++;
    }
    else {
      int left = n-i-1;
      int end = ptr-left+1;
      if (str + k < end)
        str += k;
      else {
        compact = true;
        str = end;
      }
      
    }
  }
  cout << s;

}
