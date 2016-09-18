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

#define MAXN 111
#define MAXM 11111

int a[MAXN];
int f[MAXN][MAXM];

int main() {
  int numt;
  cin >> numt;
  while (numt--) {
    int n, m, k;
    cin >> n >> m >> k;
    FOR (i, 1, n) {
      cin >> a[i];
    }

    f[0][0] = 1;
    FOR (i, 1, n) {
      FOR (j, 0, m) {
        f[i][j] = f[i - 1][j];
        if (j >= a[i]) {
          f[i][j] = min(k, f[i][j] + f[i - 1][j - a[i]]);
        }
      }
    }

    if (f[n][m] == k) {
      cout << "ENOUGH" << endl;
    } else {
      cout << f[n][m] << endl;
    }
  }
}

