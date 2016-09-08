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

ll a, b;
ll res = -1;
ll best;

ll gcd(ll x, ll y) {
  if (y == 0) return x;
  else return gcd(y, x % y);
}

void check(ll d) {
  ll n = a % d == 0 ? d : d - a % d;
  ll temp = (a + n) * (b + n) / gcd(a + n, b + n);
  if (res == -1 || temp < best || (temp == best && n < res)) {
    best = temp;
    res = n;
  }
}

int main() {
  cin >> a >> b;
  ll c = abs(a - b);

  if (a == 0 || b == 0) {
    res = 1;
  } else if (a == b) {
    res = 1;
  } else {
    for (ll i = 1; i * i <= c; i++) {
      if ((c % i) == 0) {
        check(i);
        check(c / i);
      }
    }
  }

  cout << res << endl;
}

