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
  ll n, l, k;
  double v1, v2;

  while (cin >> n >> l >> v1 >> v2 >> k) {
    ll m = (n + k - 1) / k;

    double res = l / (v1 + 1 / (m / (v2 - v1) + (m - 1) / (v1 + v2)));

    printf("%.10lf\n", res);
  }
}

