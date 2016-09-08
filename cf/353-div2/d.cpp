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

map<int, int> l, r;

int main() {
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n) {
    l.clear();
    r.clear();
    set<int> s;
    FOR (i, 1, n) {
      int y;
      cin >> y;
      if (i > 1) {
        set<int>::iterator it = s.upper_bound(y);
        int res;
        if (it == s.end()) {
          it--;
          res = *it;
          r[res] = y;
        } else if (it == s.begin()) {
          res = *it;
          l[res] =  y;
        } else {
          int z = *it;
          it--;
          int x = *it;
          if (r[x] == 0) {
            res = x;
            r[x] = y;
          } else {
            res = z;
            l[z] = y;
          }
        }
        cout << res << " ";
      }
      s.insert(y);
    }
    cout << endl;
  }
}

