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

#define MOD 1000003

ll n, k;

ll pow(ll x, ll y) {
  if (y == 1) return x % MOD;
  ll t = pow(x, y / 2);
  t = (t * t) % MOD;
  if (y % 2 == 0) return t;
  else return (t * x) % MOD;
}

ll calcT() {
  ll t = 0;
  for (int i = 1; i <= n && (1LL) << i <= k; i++) {
    t += k / ((1LL) << i);
  }
}

ll calcA() {
}

int main() {
  cin >> n >> k;
  ll t = calcT();
  ll b = pow(2, n - t);
}

