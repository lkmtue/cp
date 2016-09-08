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

int n, k;
double p[1000];
vector<double> list;
double best;

int nbit1(int s) {
  int r = 0;
  REP(i, n) {
    r += (s >> i) & 1;
  }
  return r;
}

int bit(int s, int i) {
  return (s >> i) & 1;
}

void solve() {
  best = -1;
  REP (choose, 1 << n) {
    if (nbit1(choose) != k) {
      continue;
    }

    list.clear();
    REP (i, n) {
      if (bit(choose, i)) {
        list.push_back(p[i]);
      }
    }

    double total = 0;
    REP (s, 1 << k) {
      if (nbit1(s) != k / 2) {
        continue;
      }
      double t = 1;
      REP (i, k) {
        if (bit(s, i)) {
          t *= list[i];
        } else {
          t *= 1 - list[i];
        }
      }
      total += t;
    }

    if (best < total) {
      best = total;
    }
  }
}

int main() {
  int numt;
  cin >> numt;
  FOR (test, 1, numt) {
    cin >> n >> k;
    REP (i, n) cin >> p[i];
    solve();
    printf("Case #%d: %.10lf\n", test, best);
  }
}

