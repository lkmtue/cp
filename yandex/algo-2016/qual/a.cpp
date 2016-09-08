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

string a[1011];

int diff(int i, int j) {
  int cnt = 0;
  REP(k, a[i].size()) {
    if (a[i][k] != a[j][k]) {
      cnt++;
    }
  }
  return cnt;
}

int main() {
  int n;
  cin >> n;
  FOR (i, 1, n) {
    cin >> a[i];
  }
  FOR (i, 1, n) {
    bool ok = true;
    FOR (j, 1, n) {
      if (i != j && diff(i, j) > 1) {
        ok = false;
      }
    }
    if (ok) {
      cout << a[i];
      return 0;
    }
  }
}

