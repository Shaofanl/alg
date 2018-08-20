// pick the worst cha
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void inline accelerate_io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }


#ifndef COMPONENTS_CPP
#define COMPONENTS_CPP

class Stripe {
  private:
    Stripe() {}
    string stripe;
    ll N;

  public:
    Stripe(istream& stream) {
      stream >> stripe;
      N = stripe.size();
    }

    const char& operator[] (ll index) const {
      if (index >= N) 
        index %= N;
      return stripe[index];
    }
};


class Bottles {
  private:
    Bottles() {}
    string bottles;
    ll H, ptr;
    vector<int> hand;

  public:
    Bottles(istream& stream, ll H) {
      this->H = H;

      stream >> bottles;
      hand.resize(H, 0);

      for (ptr = 0; ptr < H; ++ptr) {
        hand[bottles[ptr]-'A'] += 1;
      }
    }

		const char& operator[] (int index) {
			return bottles[index];
		}

    void printHand() const {
      for (int i = 0; i < H; ++i)
        cout << char('A'+i) << ": " << hand[i] << " | ";
      cout << endl;
    }

    void useBottle(char color) { useBottle(int(color-'A')); }

    void useBottle(int color) {
      if (hand[color] <= 0) throw runtime_error("invalid bottle");
      hand[color] --;
      if (ptr < bottles.size()) hand[bottles[ptr++]-'A']++;
    }
};

class ChameleonsFarm {
  private:
    vector<ll> pos;
    unordered_set<ll> pos_set;
    ll U;

    ChameleonsFarm() {}
    Bottles* bottles;
    Stripe* stripe;

  public:
    ChameleonsFarm(Bottles* bottles, Stripe* stripe, ll U) {
      this->bottles = bottles;
      this->stripe = stripe;
      this->U = U;

      for (int i = 0; i < U; ++i) {
        pos.push_back(i);
        pos_set.insert(i);
      }
    }

    void action(int cha, char color) { action(cha, int(color-'A')); }

    void action(int cha, int color) {
      bottles->useBottle(color);

      int p = pos[cha]+1;
      while ((*stripe)[p]-'A' != color || pos_set.find(p)!=pos_set.end())
        p++;
      pos_set.erase(pos[cha]);
      pos[cha] = p;
      pos_set.insert(p);
    }

    void printFarm() {
      for (int i = 0; i < U; ++i) 
        cout << "pos[" << i << "] = " << pos[i] << "\t";
      cout << endl;
    }

		int worstCha() {
			int worst = 0;
			for (int i = 1; i < U; ++i)
				if (pos[i] < pos[worst])
					worst = i;
			return worst;
		}
};
#endif
// #include "components.cpp"

int main(int argc, char** argv) {
  accelerate_io();

  ll N, S, C, H, U;
  cin >> N >> S >> C >> H >> U;
  Stripe stripe(cin);
  Bottles bottles(cin, H);
  ChameleonsFarm farm(&bottles, &stripe, U);
	// farm.printFarm();

	
	for (int i = 0; i < S; ++i) {
    cout << farm.worstCha() << " " << bottles[i] << endl;
		farm.action(farm.worstCha(), bottles[i]);
		// farm.printFarm();
	}

}
