/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  vector<int> a;
  int n;
  cin >> n;

  while (n--) {
    int temp;
    cin >> temp;
    a.push_back(temp);
  }

  sort(a.begin(), a.end());

  if (a.size() == 1)
    cout << a[0] << endl;
  else
    cout << a[(a.size()-1)/2] << endl; 

}
