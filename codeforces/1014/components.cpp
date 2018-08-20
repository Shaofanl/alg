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
    ll ptr;

  public:
    vector<int> hand;
    ll H;
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
      if (hand[color] <= 0) {
        cout << "invalid bottle" << endl;
        cout << color << endl;
        printHand();
        throw runtime_error("invalid bottle");
      }
      hand[color] --;
      if (ptr < bottles.size()) hand[bottles[ptr++]-'A']++;
    }

    int nextFilling() {
      if (ptr < bottles.size())
        return bottles[ptr]-'A';
      else
        return -1;
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

    int estimate(int cha, char color) { return estimate(cha, int(color-'A')); }
    int estimate(int cha, int color) {
      int p = pos[cha]+1;
      while ((*stripe)[p]-'A' != color || pos_set.find(p)!=pos_set.end())
        p++;
      return p;
    }

    int action(int cha, char color, bool probe=false) { return action(cha, int(color-'A'), probe); }

    int action(int cha, int color, bool probe=false) {
      if (!probe)
        bottles->useBottle(color);

      int p = estimate(cha, color);
      if (!probe) {
        pos_set.erase(pos[cha]);
        pos[cha] = p;
        pos_set.insert(p);
      }
      return p;
    }

    void printFarm() {
      for (int i = 0; i < U; ++i) 
        cout << "pos[" << i << "] = " << pos[i] << "\t";
      cout << endl;
    }

		int worstCha() {
			int worst = 0;
			for (int i = 1; i < U; ++i)
				if (pos[i] != -1 && pos[i] < pos[worst])
					worst = i;
			return worst;
		}

    int secondWorstCha() {
      int worst = worstCha();
      ll temp = pos[worst];
      pos[worst] = -1;
      int secondWorst = worstCha();
      pos[worst] = temp;
      return secondWorst;
    }

    int bestHand(int j) {
      int best = -1;
      ll bestDist = -1;
      for (int i = 0; i < bottles->H; ++i) 
        if (bottles->hand[i] > 0) {
          ll dist = action(j, i, true);
          if (best == -1 || dist > bestDist) {
            best = i;
            bestDist = dist;
          }
        }
      return best;
    }

    int worstHand(int j) {
      int worst = -1;
      ll worstDist = -1;
      for (int i = 0; i < bottles->H; ++i) 
        if (bottles->hand[i] > 0) {
          ll dist = action(j, i, true);
          if (worst == -1 || dist < worstDist) {
            worst = i;
            worstDist = dist;
          }
        }
      return worst;
    }

};
#endif


