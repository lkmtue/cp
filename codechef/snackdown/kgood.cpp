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
  int numt;
  cin >> numt;
  while (numt--) {
    string s;
    int k;
    cin >> s >> k;
    sort(s.begin(), s.end());
    vector<int> list;
    REP (i, s.size()) {
      if (i == 0 || s[i] != s[i - 1]) {
        list.push_back(1);
      } else {
        list[(int)list.size() - 1]++;
      }
    }
    ll best = (ll)1e17;
    FOR (x, 0, s.size()) {
      int y = x + k;
      ll rm = 0;
      REP (i, list.size()) {
        if (list[i] > y) {
          rm += list[i] - y;
        } else if (list[i] < x) {
          rm += list[i];
        }
      }
      best = min(best, rm);
    }
    cout << best << endl;
  }
}

