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
  int n;
  while (cin >> n) {
    vector<string> res;
    bool selected = false;
    REP (i, n) { 
      string s;
      cin >> s;
      if (!selected) {
        if (s[0] == 'O' && s[1] == 'O') {
          selected = true;
          s[0] = s[1] = '+';
        } else if (s[3] == 'O' && s[4] == 'O') {
          selected = true;
          s[3] = s[4] = '+';
        }
      }
      res.push_back(s);
    }
    if (selected) {
      cout << "YES" << endl;
      REP (i, res.size()) {
        cout << res[i] << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
}

