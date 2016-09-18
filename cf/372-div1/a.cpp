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

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  ll x = 2;
  for (ll k = 1; k <= n; k++) {
    ll y = x / k;
    ll z = (y + k + 1) / (k + 1) * (k + 1);
    ll r = (z * k) * (z * k);
    cout << z - y << endl;
  }
}

