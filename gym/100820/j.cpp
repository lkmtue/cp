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

#define MAX 11000111

ll f[MAX];

int main() {
  int e, es, ef;
  while (cin >> e >> es >> ef) {
    FOR (i, 1, e) f[i] = min((ll)1e18, 1 + f[max(0, i - es)] + f[max(0, i - ef)]);

    printf("%.6lf\n", min(200.0 / f[e], 225.0 / (f[e] + 1)));
  }
}

