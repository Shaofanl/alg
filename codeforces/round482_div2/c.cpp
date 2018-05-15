/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// bidirectional !!!!!!!!!!

vector<vector<int> > edge;
const ll N = 3e5+10;
bool visited[N] = {false};
ll n, x, y;
ll y_branch_count = -1, x_count, y_count;

ll dfs(int p) {
  visited[p] = true;
  ll acc = 1;
  for (int i = 0; i < edge[p].size(); ++i) {
    int child = edge[p][i];
    if (visited[child]) continue;
    ll branch = dfs(child);

    if (p == x) {
      if (visited[y] && y_branch_count == -1)
        y_branch_count = branch;
    }

    acc += branch;
  }

  if (p == y)
    y_count = acc;
  else if (p == x)
    x_count = acc;

  return acc;
}

int main() {
  cin >> n >> x >> y; x--; y--;

  for (int i = 0; i < n; ++i)
    edge.push_back(vector<int>());

  for (int i = 0; i < n-1; ++i) {
    int a, b;
    cin >> a >> b;
    edge[a-1].push_back(b-1);
    edge[b-1].push_back(a-1);
  }

  dfs(x);
  cout << (n*(n-1)-(x_count-y_branch_count)*(y_count)) << endl;;

// cout << y_count << ' ' << x_count << ' ' << y_branch_count << endl;
}
