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

#define MAX 10

int n;
int a[MAX][MAX], b[MAX][MAX];
int res;

bool operate[MAX], come[MAX];
int list[MAX];
bool can;

int bit(int s, int i) {
  return (s >> i) & 1;
}

void attempt1(int x) {
  if (x == n) {
    return;
  }

  bool found = false;
  REP (i, n) {
    if (!operate[i] && b[list[x]][i] == 1) {
      found = true;
      operate[i] = true;
      attempt1(x + 1);
      operate[i] = false;
      if (!can) return;
    }
  }
  if (!found) {
    can = false;
    return;
  }
}

void attempt(int x) {
  if (x == n) {
    attempt1(0);
    return;
  }
  REP (i, n) {
    if (!come[i]) {
      come[i] = true;
      list[x] = i;
      attempt(x + 1);
      come[i] = false;
      if (!can) return;
    }
  }
}

bool check() {
  can = true;
  attempt(0);
  return can;
}

void solve() {
  res = 1000111000;
  REP (s, 1 << (n * n)) {
    int cost = 0;
    bool ok = true;
    REP (i, n) {
      REP (j, n) {
        b[i][j] = bit(s, i * n + j);
        if (b[i][j] == 0 && a[i][j] == 1) {
          ok = false;
        }
        if (b[i][j] == 1 && a[i][j] == 0) {
          cost++;
        }
      }
    }
    if (!ok) {
      continue;
    }
    REP (i, n) {
      REP (j, n) {
        //cout << b[i][j];
      }
    }
    if (check()) {
      res = min(res, cost);
    }
  }
}

int main() {
  int numt;
  cin >> numt;
  FOR (test, 1, numt) {
    cin >> n;
    REP (i, n) {
      string s;
      cin >> s;
      REP (j, n) a[i][j] = s[j] - '0';
    }
    solve();
    printf("Case #%d: %d\n", test, res);
  }
}

