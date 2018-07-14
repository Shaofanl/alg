#include <bits/stdc++.h>

using namespace std;

int numDecodeWay(string s) {
  // write your solution here

  int last_last = 0, last = 1;
  for (int i = 0; i < s.size(); ++i) {
    int next = 0;
    if (s[i] != '0')
      next = last;      
    if (i >= 1 && (s[i-1]-'0')*10+s[i]-'0' <= 26)
      next += last_last;
    last_last = last;
    last = next;
    cout << last_last << " " << last << " " << next << endl;
  }
  if (s[s.size()-1] == '0') return last_last;
  else return last;
}

int main(){
  cout << numDecodeWay(string("012")) << endl;
}
