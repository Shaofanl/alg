#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }



int main(int argc, char** argv) {
  accelerate_io();
  ifstream example, operation;

  if (argc < 3) {
    cerr << "#arg must be greater than 3" << endl;
    example.open("examples/000");
    operation.open("op.out");
    // return EXIT_FAILURE;
  }
  else {
    example.open(argv[1]);
    operation.open(argv[2]);
  }
  
  ll N, S, C, H, U;
  example >> N >> S >> C >> H >> U;
  Stripe stripe(example);
  Bottles bottles(example, H);
  ChameleonsFarm farm(&bottles, &stripe, U);
  farm.printFarm();

  /*
    bottles.printHand();
    bottles.useBottle('H');
    bottles.printHand();
    bottles.useBottle('H');
    bottles.printHand();
  */

  int cha;
  char color;
  while (operation >> cha >> color) {
    farm.action(cha, color);
    farm.printFarm();
  }
}
