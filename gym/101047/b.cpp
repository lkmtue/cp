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
  int t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;

    vector<int> res;

    FOR (base, 2, 16) {
      ll x = n;
      vector<int> d;

      while (x) {
        d.push_back(x % base);
        x /= base;
      }

      bool ok = true;
      int nd = d.size();
      REP (i, nd) {
        if (d[i] != d[nd - 1 - i]) {
          ok = false;
        }
      }

      if (ok) res.push_back(base);
    }

    if (res.empty()) cout << -1;
    REP (i, res.size()) cout << res[i] << " ";
    cout << endl;
  }

}

