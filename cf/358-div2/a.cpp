#include <algorithm>
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

ll cnt(int x, int i) {
  int res = 0;
  FOR (j, 1, x) {
    if (j % 5 == i) {
      res++;
    }
  }
  return res;
}

int main() {
  int m, n;
  while (cin >> m >> n) {
    ll res = 0;
    REP (i, 5) {
      int j = (5 - i) % 5;
      res += cnt(m, i) * cnt(n, j);
    }
    cout << res << endl;
  }
}

