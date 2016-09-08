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

#define MOD 1000000007

ll p(ll x, ll y) {
  if (y == 0) return 1;
  if (y == 1) return x % MOD;
  ll t = p(x, y / 2);
  t = (t * t) % MOD;
  if (y % 2 == 1) t = (t * x) % MOD;
  return t;
}

ll nDigit(ll x) {
  ll d = 0;
  while (x) {
    d++;
    x /= 10;
  }
  return d;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll m, n;
    cin >> n >> m;

    ll d = nDigit(m);

    ll a = (p(10, d * n) - 1 + MOD) % MOD;
    ll b = p((p(10, d) - 1 + MOD) % MOD, MOD - 2);
    ll c = (a * b) % MOD;
    ll res = (c * m) % MOD;

    cout << res << endl;
  }
}

