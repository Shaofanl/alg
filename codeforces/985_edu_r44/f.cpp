/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
#define _for(iter, l, h) for (int iter = l; iter < h; iter++)
#define _forr(iter, h, l) for (int iter = h; iter > l; iter--)
typedef pair<ll, ll> p_ll;

// segment tree, be careful about the start (0 or 1)
const ll MAXN = 2*1e5+1;
ll a[MAXN], ans[MAXN << 2];
// a: original info
// ans: summary of trees
// lazy: delayed update (update [1,12] but not [1, 6] and [7, 12]) 


ll inline _lchild(ll node) { return node << 1; }
ll inline _rchild(ll node) { return node << 1 | 1; }

void push_up(ll node) {
  ans[node] = ans[_lchild(node)] | ans[_rchild(node)];
}

void build(ll l, ll r, ll node) {
  if (l == r) {
    ans[node] = a[l];
    return;
  }
  ll mid = (l+r) >> 1;
  build(l, mid, _lchild(node));
  build(mid+1, r, _rchild(node));
  push_up(node);
}

ll query(ll L, ll R, ll range_l, ll range_r, ll node) {
  if (L <= range_l && range_r <= R)
    return ans[node];
//  cout << range_l << " " << range_r << endl;

  ll res = 0;
  ll mid = (range_l+range_r) >> 1;
  if (L <= mid) res |= query(L, R, range_l, mid, _lchild(node));
  if (R > mid)  res |= query(L, R, mid+1, range_r, _rchild(node));
  return res;
}

ll inline charToBit(char c) { return ll(1) << (c-'a'); }
ll inline countBit(ll b) {
  ll res = 0;
  while (b) {
    res += b & 1;
    b >>= 1;
  }
  return res;
}

int main() {
  accelerate_io();

  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;

  _for(i, 1, n+1)
    a[i] = charToBit(s[i-1]);
  build(1, n, 1);

  while (m--) {
    ll x, y, len;
    cin >> x >> y >> len;
    ll bx = countBit(query(x, x+len-1, 1, n, 1));
    ll by = countBit(query(y, y+len-1, 1, n, 1));
// cout << bx << " " << by << endl;
    cout << (bx==by?"YES":"NO") << endl; 
  }

}
