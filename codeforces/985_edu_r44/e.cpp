/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
#define _for(iter, l, h) for (int iter = l; iter < h; iter++)
#define _forr(iter, h, l) for (int iter = h; iter > l; iter--)
typedef pair<ll, ll> p_ll;

// DP, twopoint set maintainance

int main() {
  accelerate_io();

  ll n, k, d;
  cin >> n >> k >> d;
  vector<ll> a;
  // copy_n(istream_iterator<ll>(cin), n, back_inserter(a));
  for (int i = 0; i < n; ++i) {
    ll tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

  sort(a.begin(), a.end());
//copy(a.begin(), a.end(), ostream_iterator<ll>(cout, ", "));
//auto cmp = [] (p_ll left, p_ll right) { 
//  return left.first > right.first || (left.first == right.first && left.second > right.second); };
//priority_queue<p_ll, std::vector<p_ll>, decltype(cmp) > range(cmp);
  deque<p_ll> range;
  range.push_back(make_pair(0, 0));

  int ptr = 0;
  while (!range.empty()) {
    auto r = *range.begin(); range.pop_front();
//    cout << "range " << r.first << ", " << r.second << endl;
    if (r.first > ptr)
      ptr = r.first;

//    cout << "ptr: " << ptr << endl;
    for (int i = ptr; i < a.size() && i <= r.second; ++i) {
        ll end = distance(
            a.begin(),
            upper_bound(a.begin()+i, a.end(), a[i]+d)
            );
        if (!range.empty() && range.rbegin()->first <= i+k && i+k <= range.rbegin()->second)
          range.rbegin()->second = max(end, range.rbegin()->second);
        else
          range.push_back(make_pair(i+k, end));
//        cout << i << ',' << k << '>';
//        cout << i+k << " " << end << endl;
        if (i+k <= n && n <= end) {
          cout << "YES" << endl;
          return 0;
        }
      }
    ptr = r.second-1;
  }
  cout << "NO" << endl;

}
