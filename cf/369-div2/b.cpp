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

#define MAX 511
int a[MAX][MAX];

int main() {
  int n;
  while (cin >> n) {
    int x, y;
    REP (i, n) REP (j, n) {
      scanf("%d", &a[i][j]);
      if (a[i][j] == 0) {
        x = i;
        y = j;
      }
    }
    if (n == 1) {
      cout << 1 << endl;
    } else {
      int k = x == 0 ? 1 : 0;
      ll res = 0;
      ll sum = 0;
      REP (j, n) {
        sum += a[k][j];
        res += a[k][j];
        res -= a[x][j];
      }

      if (res <= 0) {
        cout << -1 << endl;
      } else {
        a[x][y] = res;
        bool ok = true;
        REP (i, n) {
          ll sumI = 0;
          REP (j, n) {
            sumI += a[i][j];
          }
          if (sumI != sum) {
            ok = false;
          }
        }

        REP (j, n) {
          ll sumJ = 0;
          REP (i, n) {
            sumJ += a[i][j];
          }
          if (sumJ != sum) {
            ok = false;
          }
        }

        ll sumD = 0;
        REP (i, n) {
          sumD += a[i][i];
        }
        if (sumD != sum) {
          ok = false;
        }

        sumD = 0;
        REP (i, n) {
          sumD += a[i][n - 1 - i];
        }
        if (sumD != sum) {
          ok = false;
        }

        if (ok) {
          cout << res << endl;
        } else {
          cout << -1 << endl;
        }
      }
    }
  }
}

