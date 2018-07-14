/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
#define _for(iter, l, h) for (int iter = l; iter < h; iter++)
#define _forr(iter, h, l) for (int iter = h; iter > l; iter--)


int lot[4][50*2] = {0},
    dps[4][50*2];
int n, k;
bool visited[4][50*2] = {0};
vector<pair<int, int>> move_order;
vector<vector<pair<int, int>>> moves;
vector<int> current_move;
int min_moves = -1;
const int kx[] = {+1, -1, 0, 0},
      int ky[] = {0, 0, +1, -1};

void search(int x, int y, int key) {
  visited[x][y] = true;

  for (int k = 0; k < 4; ++k) {
    int xx = x+kx[k], yy = y+ky[k];
    if (xx < 0 || xx >= 4 || yy < 0 || yy >= 2*n) return;
    if (visited[xx][yy]) return;

    moves.push_back(make_pair(xx, yy));
    search(xx, yy);
  }

}

int main() {
  cin >> n >> k;

  for (int i = 0; i < k; ++i)
    moves.push_back(vector<int>());
  for (int i = 0; i < 4; ++i) 
    for (int j = 0; j < 2*n; ++j) {
      cin >> lot[i][j];
      if (lot[i][j] == 0 && (i==0||i==3)) lot[i][j] = -1;
    }
  memcpy(dps, lot, sizeof(lot));

  int cost_acc = 0;
  for (int i = 0; i < k; ++i) {
    int mincost = -1;
    int mincar_x, mincar_y;

    for (int k = 1; k <=2; ++k) {
      for (int j = 0; j < 2*n; ++j) {
        if (lot[k][j]) {

          memset(visited, 0, sizeof(visited)); // try std::fill
          min_moves = -1;
          current_move.clear();
          search(k, j, lot[k][j]);
          int cost = min_moves; 

          if (cost > 0 && (mincost == -1 || mincost > cost)) {
            mincost = cost;
            mincar_x = k;
            mincar_y = j;
          }
        }
      }
    }

    cost_acc += cost;
    if (mincost == -1 || cost > 20000) {
      cout << -1 << endl;
      return 0;
    }
    move_order.push_back(make_pair(mincar_x, mincar_y));
    dps[mincar_x, mincar_y] = 0;
  }

  cout << cost_acc << endl;
  for (int i = 0; i < k; ++i)
    move(mincar_x, mincar_y);
}
