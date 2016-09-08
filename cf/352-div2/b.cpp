#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool a[300];

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n > 26) {
    cout << -1 << endl;
  } else {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      if (a[s[i]]) {
        res++;
      }
      a[s[i]] = true;
    }
    cout << res << endl;
  }
}
