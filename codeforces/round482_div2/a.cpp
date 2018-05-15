#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n;
  cin >> n;
  if (n == 0)
    cout << 0 << endl;
  else
    cout << ((n+1)%2==0?(n+1)/2:n+1) << endl;;
}
