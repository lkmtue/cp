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

#define MAX 3111

ll a[MAX], b[MAX];
ll f[MAX][MAX];

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  FOR (i, 1, n) {
    cin >> a[i];
    a[i] -= i;
    b[i] = a[i];
  }

  sort(b + 1, b + n + 1);

  FOR (i, 1, n) {
    FOR (j, 1, n) {
      if (j == 1) {
        f[i][1] = abs(a[i] - b[1]) + f[i - 1][1];
      } else {
        f[i][j] = min(f[i][j - 1], f[i - 1][j] + abs(a[i] - b[j]));
      }
    }
  }

  ll res = 1e18;
  FOR (j, 1, n) res = min(res, f[n][j]);
  cout << res << endl;
}

