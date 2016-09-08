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

int a[111][111];

int main() {
  int _;
  cin >> _;
  while (_--) {
    int n;
    cin >> n;
    FOR (i, 1, n) FOR (j, 1, n) cin >> a[i][j];

    int d = 0;

    vector<int> all;

    FOR (i, 1, 2 * n - 1) {
      int x, y;

      if (i <= n) {
        x = i;
        y = 1;
      } else {
        x = n;
        y = i - n + 1;
      }

      vector<int> res;

      while (1 <= x && x <= n && 1 <= y && y <= n) {
        res.push_back(a[x][y]);
        x -= 1;
        y +=1 ;
      }

      if (d == 1) {
        reverse(res.begin(), res.end());
      }

      REP (i, res.size()) all.push_back(res[i]);

      d = 1 - d;
    }

    REP(i, all.size()) {
      cout << all[i] << " ";
      if (i % n == n - 1) cout << endl;
    }
  }
}

