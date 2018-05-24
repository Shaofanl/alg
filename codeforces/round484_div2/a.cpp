/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
#define _for(iter, l, h) for (int iter = l; iter < h; iter++)
#define _forr(iter, h, l) for (int iter = h; iter > l; iter--)

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int cnt = 0;
  bool valid = true;
  for (char c: s)
    cnt += c=='1';

  for (int i = 1; i < s.size(); ++i)
    if (s[i] == s[i-1] && s[i] == '1')
      valid = false;

  if (cnt == (n+1)/2 && valid)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
