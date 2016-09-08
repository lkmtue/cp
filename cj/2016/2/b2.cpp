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

#define MAX 211

int n, k;
double p[MAX];
double f[MAX][MAX];
double res;

vector<double> a;

double calc() {
  memset(f, 0, sizeof(f));

  f[0][0] = 1 - a[0];
  f[0][1] = a[0];

  FOR (i, 1, k - 1) {
    FOR (j, 0, min(i + 1, k / 2)) {
      if (i >= j) {
        f[i][j] = f[i - 1][j] * (1 - a[i]);
      }
      f[i][j] += f[i - 1][j - 1] * a[i];
    }
  }

  return f[k - 1][k / 2];
}

void solve() {
  res = 0;
  sort(p, p + n);
  FOR (i, 0, k) {
    a.clear();
    REP (j, i) {
      a.push_back(p[j]);
    }
    FORD (j, n - 1, n - (k - i)) {
      a.push_back(p[j]);
    }
    res = max(res, calc());
  }
}

int main() {
  int numt;
  cin >> numt;
  FOR (test, 1, numt) {
    cin >> n >> k;
    REP (i, n) cin >> p[i];
    solve();
    printf("Case #%d: %.10lf\n", test, res);
  }
}

