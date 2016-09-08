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

set<int> d, b;

void flip(int i) {
  auto it = d.find(i);
  if (it != d.end()) {
    d.erase(it);
    b.insert(i);
  } else {
    it = b.find(i);
    if (it != b.end()) {
      b.erase(it);
      d.insert(i);
    }
  }
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    string a;
    cin >> a;
    a = " " + a;

    d.clear();
    b.clear();

    FOR (i, 1, n) {
      if (a[i] == 'D') d.insert(i);
      else b.insert(i);
    }

    vector<int> res;

    while (!d.empty()) {
      int i = *d.begin();
      res.push_back(i);

      d.erase(d.begin());

      flip(i - 1);
      flip(i + 1);
    }

    if (res.size() == n) {
      cout << "Y" << endl;
      REP (i, n) cout << res[i] << " ";
      cout << endl;
    } else {
      cout << "N" << endl;
    }
  }
}

