#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORN(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define BUG(x) cerr << #x << " = " << x << endl

int f[100111];

int main() {
  int k;
  cin >> k;
  string s;
  cin >> s;
  int n = s.size();
  s = " " + s;
  FOR (i, 1, n) {
    if (s[i] == '1') {
      int &j = f[(i - 1 + k) % k];
      if (j) {
        cout << j << " " << i << endl;
        return 0;
      }
      f[i % k] = i;
    }
  }
  cout << "0 0" << endl;
}

