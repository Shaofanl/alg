/// could be better
#include <bits/stdc++.h>

using namespace std;

void inline p(int count, char c = '.', bool ending = false) {
	if (count > 0)
		cout << string(count, c);
  if (ending) cout << endl;
}

void inline odd_line(int count, int n) {
	if (count == 1) {
    p((n)/2, '.'); p(1, '#'); p((n)/2, '.', true);
	}
	else {
		p(1, '.'); 
		int step = (n-3)/(count-1);
		for (int i = 0; i < n-2; i++) 
			cout << (i%step==0?'#':'.');
		p(1, '.', true); 
	}
}

void inline even_line(int count, int n) {
	p(1, '.'); 
	p(count/2, '#');
	p(n - count-2, '.');
	p(count/2, '#');
	p(1, '.', true); 
}

int main() {
  int n, k;
  cin >> n >> k;

  if (k % 2 == 0) {
		cout << "YES" << endl;
    p(n, '.', true);
    p(1, '.'); p(k/2, '#'); p(n-k/2-1, '.', true);
    p(1, '.'); p(k/2, '#'); p(n-k/2-1, '.', true);
    p(n, '.', true);
  }
  else if (k == n-2) {
		cout << "YES" << endl;
    p(n, '.', true);
    p(1, '.'); p(k, '#'); p(1, '.', true);
    p(n, '.', true);
    p(n, '.', true);
  }
	else if (k >= n-2+2) {
		cout << "YES" << endl;
    p(n, '.', true);
    p(1, '.'); p(n-2, '#'); p(1, '.', true);
    p(1, '.'); p(1, '#'); p(k-n, '#'); p(n-4-(k-n), '.'); p(1, '#'); p(1, '.', true);
    p(n, '.', true);
	}
	else if (k==1 && (n-2) % 2 == 1) {
		cout << "YES" << endl;
    p(n, '.', true);
    p((n)/2, '.'); p(1, '#'); p((n)/2, '.', true);

    p(n, '.', true);
    p(n, '.', true);
	}
	else if (k-1>0 && (n-3) % (k-1) == 0) {
		cout << "YES" << endl;
		p(n, '.', true);
		
		p(1, '.'); 
		int step = (n-3)/(k-1);
		for (int i = 0; i < n-2; i++) 
			cout << (i%step==0?'#':'.');
		p(1, '.', true); 

    p(n, '.', true);
    p(n, '.', true);
	}
	else {
		for (int i = 1; i <= k; ++k) {
			if (k%i == 0 && k-i<=n-2) {
				cout << "YES" << endl;
				p(n, '.', true);
				odd_line(i, n);
				even_line(k-i, n);
				p(n, '.', true);
				return 0;
			}
		}
		cout << "NO" << endl;
	}
}
