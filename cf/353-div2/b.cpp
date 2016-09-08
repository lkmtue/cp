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

int main() {
  int n, a, b, c, d;
  while (cin >> n >> a >> b >> c >> d) {
    ll res = 0;
    FOR(x, 1, n) {
      int u = max(max(x + a + b + 1, x + a + c + 1), max(x + b + d + 1, x + c + d + 1));
      int v = min(min(x + a + b + n, x + a + c + n), min(x + b + d + n, x + c + d + n));
      if (u <= v) {
        res += v - u + 1;
      }
    }
    cout << res << endl;
  }
}

