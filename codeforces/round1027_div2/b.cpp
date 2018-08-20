/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
#define _for(iter, l, h) for (int iter = l; iter < h; iter++)
#define _forr(iter, h, l) for (int iter = h; iter > l; iter--)
/*-- templates --*/


int main() {
  accelerate_io();

  int64_t n, q;
  cin >> n >> q;
  bool odd = (n%2==1);
  int64_t half = ceil(double(n)*double(n)/2);
  // int64_t half = n/2*(n/2*2+odd)+odd?n/2:0;
  

  while (q--) {
    int64_t i, j;
    cin >> i >> j;

    int64_t count = 1;
    if ((i+j)%2 == 0) {
      count += (
          (i-1)/2*(n/2*2+odd)+
          (i%2==0?(n/2+odd):0)
      );
      count += (j-1)/2;
    }
    else {
      count += (
          (i-1)/2*(n/2*2+odd)+
          (i%2==0?(n/2):0)
      );
      count += (j-1)/2;
      count += half;
    }
    cout << count << endl;
  }
}
