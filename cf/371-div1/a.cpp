#include <algorithm>
#include <cmath>
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

map<string, int> f;

void process(ll x, int d) {
  string s = "";
  FOR (i, 1, 18) {
    s += char((x % 2) + '0');
    x /= 10;
    f[s] += d;
  }
}

int main() {
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  while (q--) {
    string c;
    cin >> c;
    if (c == "+") {
      ll x;
      cin >> x;
      process(x, 1);
    } else if (c == "-") {
      ll x;
      cin >> x;
      process(x, -1);
    } else {
      string s;
      cin >> s;
      reverse(s.begin(), s.end());
      while (s.size() < 18) s += "0";
      cout << f[s] << endl;
    }
  }
}

