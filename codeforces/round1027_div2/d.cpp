/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
#define _for(iter, l, h) for (int iter = l; iter < h; iter++)
#define _forr(iter, h, l) for (int iter = h; iter > l; iter--)
/*-- templates --*/

void dfs(int ptr, vector<bool> &colored, vector<vector<int>> & next) {
  if (colored[ptr]) return;
  colored[ptr] = true;
  for (auto &next_ptr: next[ptr])
    dfs(next_ptr, colored, next);
}

int main() {
  accelerate_io();

  int n, temp;
  cin >> n;
  vector<ll> c;
  vector<int> a;
  vector<vector<int>> reverse;

  copy_n(istream_iterator<int>(cin), n, back_inserter(c));

  for (int i = 0; i < n; ++i) {
    cin >> temp;
    a.push_back(temp-1);
    reverse.push_back(vector<int>());
  }

  for (int i = 0; i < a.size(); ++i) {
    reverse[a[i]].push_back(i);
  }

  ll cost = 0;
  vector<bool> colored(n, false);
  vector<bool> visited(n, false);
  vector<bool> loop(n, false);

  for (int i = 0; i < n; ++i)
    if (!colored[i]) {
      int ptr = i;

      // find the loop
      while (!visited[ptr]) {
        visited[ptr] = true;
        ptr = a[ptr];
      }

      // find c_min in loop
      ll min_cost_in_loop = c[ptr];
      while (!loop[ptr]) {
        loop[ptr] = true;
        ptr = a[ptr];
        min_cost_in_loop = min(min_cost_in_loop, c[ptr]);
      }

      // sum up
      cost += min_cost_in_loop;

      // flood
      dfs(ptr, colored, reverse);
    }
  cout << cost << endl;
}
