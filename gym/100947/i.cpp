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

int a[10111];

int main() {
  ios::sync_with_stdio(false);
  
  int test;
  cin >> test;
  FOR (id, 1, test) {
    int n;
    cin >> n;

    map<int, int> cnt;

    REP (i, n) {
      cin >> a[i];
      cnt[a[i]]++;
    }

    int res = 0;

    sort(a, a + n);

    REP (i, n) {
      int x = a[i];
      for (int y = 2; y * y <= x; y++) {
        if (x % y != 0) continue;
        if (cnt.find(y) != cnt.end()) {
          res += cnt[y];
        }
        if (y * y != x) {
          if (cnt.find(x / y) != cnt.end()) {
            res += cnt[x / y];
          }
        }
      }
    }

    REP (i, n) {
      if (i > 0 && a[i] == a[i - 1]) continue;

      int x = cnt[a[i]];
      res += x * (x - 1) / 2;
    }

    cout << res << endl;
  }
}

