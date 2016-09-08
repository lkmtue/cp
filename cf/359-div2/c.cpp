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

int n, m;
int len1, len2;
int a[10000];
bool used[10];

int res = 0;

int len(int x) {
  if (x == 0) return 1;
  vector<int> res;

  while (x) {
    res.push_back(x % 7);
    x /= 7;
  }

  return res.size();
}

void attempt(int x) {
  if (x > len1 + len2) {
    int u = 0, v = 0;
    FOR (i, 1, len1) u = u * 7 + a[i];
    FOR (i, len1 + 1, len1 + len2) v = v * 7 + a[i];

    if (u < n && v < m) {
      res++;
    }

    return;
  }

  REP (i, 7) if (!used[i]) {
    a[x] = i;
    used[i] = true;
    attempt(x + 1);
    used[i] = false;
  }
}

int main() {
  cin >> n >> m;
  len1 = len(n - 1);
  len2 = len(m - 1);

  attempt(1);

  cout << res << endl;
}

