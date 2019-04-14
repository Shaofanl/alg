#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
#define _for(iter, l, h) for (int iter = l; iter < h; iter++)
#define _forr(iter, h, l) for (int iter = h; iter > l; iter--)
typedef pair<ll, ll> p_ll;
typedef int64_t i64;

/*-- templates --*/

// !!!!!!!!!!! init status !!!!!!!!!
// start with 0

ll n, k;
i64 maxv = 0;
bool first_flag = true;
vector<i64> a;

i64 inline f(int start, int end) { 
  if (start == 0)
    return a[end];
  else
    return a[end] - a[start-1];
}

// vector<int> ans;

void search(int start, int left, i64 acc)  {
//cout << acc << " => ";
//copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, ", "));
//cout << endl;

  if (left == 0) {
    maxv = max(acc, maxv);
    return;
  }

  if (left == 1) {
//    ans.push_back(n-1);
    search(-1, 0, acc&f(start, n-1));
//    ans.pop_back();
  }
  else 
    for (int end = start; end < n-left+1; ++ end) {
//      ans.push_back(end);
      search(end+1, left-1, left==k?f(start,end):(acc&f(start, end)));
//      ans.pop_back();
    }
}


int main() {
  accelerate_io();

#define _DEBUG
#ifdef _DEBUG
  n = 50;
  k = 25;
  _for(i, 0, n) a.push_back(i);
#else
  cin >> n >> k;
  copy_n(istream_iterator<i64>(cin), n, back_inserter(a));
#endif



  _for(i, 1, n)
    a[i] += a[i-1];
//  copy(a.begin(), a.end(), ostream_iterator<i64>(cout, ", "));

  search(0, k, 0);

  cout << maxv << endl;
}
