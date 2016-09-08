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

int main() {
  int n;
  while (cin >> n) {
    int p1, pn;
    REP (i, n) {
      int x;
      cin >> x;
      if (x == 1) p1 = i;
      if (x == n) pn = i;
    }
    int res = abs(p1 - pn);
    if (p1 != 0 && pn != 0) {
      res = max(res, p1);
      res = max(res, pn);
    }
    if (p1 != n - 1 && pn != n - 1) {
      res = max(res, n - 1 - p1);
      res = max(res, n - 1 - pn);
    }
    cout << res << endl;
  }
}

