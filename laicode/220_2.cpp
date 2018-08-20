#include <bits/stdc++.h>
using namespace std;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
#define _for(iter, l, h) for (int iter = l; iter < h; iter++)
#define _forr(iter, h, l) for (int iter = h; iter > l; iter--)
typedef long long ll;
typedef unsigned long long ull;
typedef int64_t i64;
/*-- templates --*/



const int N = 8*8;
const ull FILLED = ull(-1);
const ull mask ;// hard to set the boundary for the one on the edge

vector<int> arr(N, 0);

int main() {
  ifstream f("220.inp");

  bool all_non_pos_flag = true;
  int temp_max = INT_MIN;
  for (int i = 0; i < N; ++i) {
      f >> arr[i];
      all_non_pos_flag &= (arr[i] <= 0);
      temp_max = max(temp_max, arr[i]);
  }
  if (all_non_pos_flag) {
    cout << temp_max << endl;
    return EXIT_SUCCESS;
  }


}
