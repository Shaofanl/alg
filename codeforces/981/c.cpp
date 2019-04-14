#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
#define _for(iter, l, h) for (int iter = l; iter < h; iter++)
#define _forr(iter, h, l) for (int iter = h; iter > l; iter--)
typedef pair<ll, ll> p_ll;

/*-- templates --*/

const int MAXN = 1e5+3;
vector<vector<int> > con;
bool visited[MAXN];
ll keypoint = 0;

int main() {
  accelerate_io();

  ll n;
  cin >> n;

  _for(i, 0, n)
    con.push_back(vector<int>());

  _for(_, 0, n-1) {
    int start, end;
    cin >> start >> end;
    start -- ; end --;

    con[start].push_back(end);
    con[end].push_back(start);
  }

  ll keypoint = -1;
  _for(i, 0, n) {
    if (con[i].size() >=3) {
      if (keypoint == -1)
        keypoint = i;
      else {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  if (keypoint == -1) keypoint = 0;
  cout << "Yes" << endl;
  cout << con[keypoint].size() << endl;

  visited[keypoint] = true;
  for (int dir: con[keypoint]) {
    cout << keypoint+1 << ' ';

    while (con[dir].size() > 1) {
      visited[dir] = true;
      for (auto next: con[dir]) {
        if (! visited[next]) {
          dir = next;
          break;
        }
      }
    }
    cout << dir+1 << endl;
  }

}
