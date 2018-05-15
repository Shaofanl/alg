/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// stupid IQ mistake

ll count(string s) {
  ll cnt[256]; 
  for (int i = 0; i < 256; ++i) cnt[i] = 0;

  for (char c: s) cnt[int(c)] ++;

  ll ans = 0;
  for (int i = 0; i < 256; ++i)
    if (cnt[i] > ans) ans = cnt[i];
  return ans;
}

ll run(string s, ll current, ll total, ll n) {
//ll cnt[256]; 
//for (int i = 0; i < 256; ++i) cnt[i] = 0;
//for (char c: s) cnt[int(c)] ++;
//ll varmax = -1, var = 0;
//for (int i = 0; i < 256; ++i) {
//  var += (cnt[i]!=0);
//  varmax = max(cnt[i], varmax);
//}
//if (var == 26*2) return varmax;


// wrong
//ll tofill = total-current;
//if (tofill >= n)
//  return current+n;
//else 
//  return total - ((n-tofill)%2==0?0:1);

  ll tofill = total-current;
  if (tofill == 0 && n == 1)
    return total-1;
  return min(current+n, total);
}

int main() {
  int n ;
  cin >> n;
  string a, b, c;
  cin >> a >> b >> c;

  ll ca = count(a), cb = count(b), cc = count(c);
//  cout << ca << ' ' << cb << ' ' << cc << endl;

  int total_l = a.size(); 
  ca = run(a, ca, total_l, n);
  cb = run(b, cb, total_l, n); 
  cc = run(c, cc, total_l, n);
  ll maxv = max(ca, max(cb, cc));

  int draw = 0;
  draw += ca==maxv;
  draw += cb==maxv;
  draw += cc==maxv;
// cout << ca << ' ' << cb << ' ' << cc << endl;

  if (draw > 1)
    cout << "Draw" << endl;
  else if (ca == maxv)
    cout << "Kuro" << endl;
  else if (cb == maxv)
    cout << "Shiro" << endl;
  else if (cc == maxv)
    cout << "Katie" << endl;
}
