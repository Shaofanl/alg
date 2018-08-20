#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }


int main(int argc, char** argv) {
  accelerate_io();

  ll N, S, C, H, U;
  string stripe, bottles;
  cin >> N >> S >> C >> H >> U;
  cin >> stripe >> bottles;

  for (int i = 0; i < S; ++i) {
    cout << i%U << " " << bottles[i] << endl;
  }
}
