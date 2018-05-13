#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s; 
  int p = 0, l = 0;
  for (int i = 0; i < s.size(); ++i) {
    p += (s[i] == 'o');
    l += (s[i] == '-');
  }

//cout << l << endl;
//cout << p << endl;
//cout << l % p << endl;
  if (p == 0)
    cout << "YES";
  else if (l % p == 0)
    cout << "YES";
  else
    cout << "NO";
}