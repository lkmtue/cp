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
    int c, d;
    cin >> c >> d;

    ll x = 1;
    REP (i, c) x *= 26;

    ll y = 1;
    REP (i, d) y *= 10;

    ll res = x * y;
    if (c == 0 && d == 0) res--;

    cout << res << endl;
  }
}

