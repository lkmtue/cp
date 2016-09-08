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
  ll a, b, c;
  while (cin >> a >> b >> c) {
    bool ok;
    if (c == 0) {
      ok = a == b;
    } else if (c > 0) {
      ok = (b >= a) && abs(b - a) % abs(c) == 0;
    } else {
      ok = (b <= a) && abs(b - a) % abs(c) == 0;
    }
    if (ok) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

