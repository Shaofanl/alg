#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
#define _for(iter, l, h) for (int iter = l; iter < h; iter++)
#define _forr(iter, h, l) for (int iter = h; iter > l; iter--)
/*-- templates --*/



const int N = 8;
const int TOTAL_STAT = 1 << N;

template<typename T>
using matrix = vector<vector<T>>;

void print_mat(matrix<int> & mat) {
  cout << "============================" << endl;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j)
      cout << mat[i][j] << ' ';
    cout << endl;
  }
}

string bin_to_str(int x) {
  string s = "";
	for (int i = 0; i < N; ++i) {
    s.append(1, '0'+(x&1));
    x >>= 1;
	}
  reverse(s.begin(), s.end());
	return s;
}

bool can_fill(int fill_bit, int invalid_bit) {
  return (
      ((fill_bit & invalid_bit) == 0)
      &&
      (((fill_bit << 1) & (fill_bit)) == 0)
      &&
      (((fill_bit >> 1) & (fill_bit)) == 0)
  );
}

int inline expand(int fill) {
	return (fill | (fill << 1) | (fill >> 1)) & ((1 << N)-1);
}

int largestSum(matrix<int> & mat) {

	// check all positive
  bool all_non_pos_flag = true;
  int temp_max = INT_MIN;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      all_non_pos_flag &= (mat[i][j] <= 0);
      temp_max = max(temp_max, mat[i][j]);
		}
	}
  if (all_non_pos_flag)
		return temp_max;

	matrix<ll> dp; // can be compressed from 8*128 to 2*128
	matrix<ll> dp_solution;

  for (int i = 0; i < N; ++i) {
    dp.push_back(vector<ll>(TOTAL_STAT, -1));
    dp_solution.push_back(vector<ll>(TOTAL_STAT, 0));
  }


  // 8 * 128 * 128 * 8
  for (int l = N-1; l >= 0; --l) {
    for (int invalid_bit = 0; invalid_bit < TOTAL_STAT; ++invalid_bit)
      for (int fill_bit = 0; fill_bit < TOTAL_STAT; ++fill_bit) 
				// can pre-generate a valid fill_bit_set
        if (can_fill(fill_bit, invalid_bit)) {

          // dp last layer
          ll value_from_next =
            l == N-1?0:dp[l+1][expand(fill_bit)];

          // collect this layer
          ll value_from_this = 0;
          for (int j = 0; j < N; ++j)
            if (fill_bit & (1 << (N-j-1)))
              value_from_this += mat[l][j];

          // dp
					ll new_value = value_from_next + value_from_this;
					if (dp[l][invalid_bit] < new_value) {
						dp[l][invalid_bit] = new_value;
						dp_solution[l][invalid_bit] = fill_bit;
					}

        }
  }

  cout << dp[0][0] << endl;

	int sol_bit = dp_solution[0][0];
	cout << bin_to_str(sol_bit) << endl;
	for (int i = 1; i < N; ++i) 
		cout << bin_to_str(sol_bit=dp_solution[i][sol_bit]) << endl;
	return dp[0][0];
}



int main() {
  ifstream f("220.inp");

	matrix<int> mat;
  for (int i = 0; i < N; ++i) {
    mat.push_back(vector<int>(N, 0));
    for (int j = 0; j < N; ++j)
      f >> mat[i][j];
  }
  print_mat(mat);


	cout << largestSum(mat) << endl;

}

