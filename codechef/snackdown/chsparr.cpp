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

#define base 1000000007LL
#define MAX 100111

int n;
int a[MAX];
ll len[100];

int get(int m, ll x) {
  if (x == 0 || x > len[m]) return 0;
  else if (m == 1) return a[x];
  else if (x % 2 == 1) return get(m - 1, x / 2 + 1);
  else return (get(m - 1, x / 2) + get(m - 1, x / 2 + 1)) % base;
}

ll solve(int m, ll x) {
  if (x == 0) return 0;

  if (m == 1) {
    ll res = 0;
    FOR (i, 1, min(x, (ll)n)) {
      res = (res + a[i]) % base;
    }
    return res;
  }
  if (x == 1) return get(m, 1);

  ll t = solve(m - 1, x / 2 + 1);
  ll subFirst = (base - get(m, 1)) % base;

  if (x % 2 == 1) {
    ll subLast = (base - get(m, x)) % base;
    return (t * 3 + subFirst + subLast) % base;
  } else {
    ll subLast = (base - get(m, x + 1)) % base;
    return (t * 3 + subFirst + 2 * subLast) % base;
  }
}

int main() {
  ios::sync_with_stdio(false);
  int _;
  cin >> _;
  while (_--) {
    int m;
    ll x, y;

    cin >> n >> m >> x >> y;
    m++;

    memset(a, 0, sizeof(a));
    FOR (i, 1, n) cin >> a[i];

    memset(len, 0, sizeof(len));
    len[1] = n;
    FOR (i, 2, m) len[i] = len[i - 1] * 2 - 1;

    ll resX = solve(m, x - 1);
    ll resY = solve(m, y);
    ll res = (resY - resX + base) % base;
    cout << res << endl;
  }
}

