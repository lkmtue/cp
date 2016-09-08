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

#define MAX 2111

int n, p, q;
int a[MAX];
int f[MAX][MAX];

void op(int &x, int &y) {
  if (y == -1) return;
  if (x == -1) x = y + 1;
  else x = min(x, y + 1);
}

bool chk(int w) {
  int k = 1;
  int l = 1;

  bool ok = false;

  FOR (i, 0, n) FOR (j, 0, n) f[i][j] = -1;
  f[0][0] = 0;

  FOR (i, 1, n) {
    while (a[i] - a[k] + 1 > w) k++;
    while (a[i] - a[l] + 1 > 2 * w) l++;

    FOR (j, 0, min(i, p)) {
      if (j > 0) {
        f[i][j] = f[k - 1][j - 1];
      }
      op(f[i][j], f[l - 1][j]);

      if (i == n && f[i][j] <= q && f[i][j] != -1) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  int ntest;
  cin >> ntest;

  REP (test, ntest) {
    cin >> n >> p >> q;
    FOR (i, 1, n) cin >> a[i];

    sort(a + 1, a + n + 1);

    int low = 1;
    int high = 1e9;
    int res = -1;

    while (low <= high) {
      int mid = (low + high) / 2;

      if (chk(mid)) {
        res = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    cout << res << endl;
  }
}

