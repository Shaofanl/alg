/*-- templates --*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// TIRE, prefix-tree

const ll MAX = 1e5+1;
const int MAX_BIT_LEN = 20;
const ll MOSTLEFT = 1 << MAX_BIT_LEN;

class Tire {
  public:
    ll minval;
    Tire* children[2];
    ll bit;

    Tire() {
      children[0] = children[1] = nullptr;
      bit = 0;
      minval = -1;
    }

    int get_branch(ll value) {
      return (value&bit)==0?0:1;
    }

    void insert(ll value, ll bit) {
      minval = (minval==-1?value:min(minval, value));

      this->bit = bit;
      if (bit == 0) return;      

      int branch = get_branch(value);
//    cout << this << "->" << branch << endl;
      if (!children[branch])
        children[branch] = new Tire();
      children[branch]->insert(value, bit >> 1);
    }

    void search(ll x, ll upper) {
      if (bit == 0) {
        cout << minval << endl;
        return;
      }
      if (minval > upper) return;

//    cout << "search branch with minval " << minval << " bit" << bit << endl;
//    cout << "value " << x << " " << children[0] << " vs " << children[1] << endl;
//    if (children[1]) {
//      cout << ">> " << (children[1]->minval<=upper) << " " << get_branch(x) << endl;
//    }

      if (!children[0] || (children[1] && children[1]->minval <= upper && get_branch(x) == 0))
        // c0 doesn't exist
        // or
        // c1 exist, c1's minval is valid, and the next bit in x is 0 
        // if next bit in x is 0 (choose 1:)0^1=1 is greater than (choose 0:)0=0^0
        // if next bit in x is 1 (choose 0:)1^0=1 is greater than (choose 1:)0=1^1
        children[1]->search(x, upper);
      // { cout << "choose 1" << endl; children[1]->search(x, upper); }
      else
        children[0]->search(x, upper);
      // { cout << "choose 0" << endl; children[0]->search(x, upper); }
    }

};

Tire tires[MAX];
vector<ll> dividable[MAX];

int main() {
  for (int i = 1; i < MAX; ++i)
    for (int j = i; j < MAX; j += i)
      dividable[j].push_back(i);
  // cout << "done" << endl;

  ll n;
  cin >> n;

  while (n--) {
    int command;
    cin >> command;
    if (command == 1) {
      ll u;
      cin >> u;
      for (int divisor: dividable[u]) 
      {
        // cout << "adding to tire " << divisor << endl;
        tires[divisor].insert(u, MOSTLEFT);
      }
    }
    else {
      ll x, k, s;
      cin >> x >> k >> s;
      if (x % k || tires[k].minval == -1 || tires[k].minval > s-x) {
        cout << "-1" << endl;
        continue;
      }
      tires[k].search(x, s-x);
    }
  }
}
