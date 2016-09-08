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

int a[100111];

int main() {
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  s = " " + s;
  FOR (i, 1, n) {
    a[i] = a[i - 1] + (s[i] == 'a' ? 1 : 0);
  }

  int low = 1;
  int high = n;
  int res;

  while (low <= high) {
    int mid = (low + high) / 2;
    bool ok = false;

    FOR (i, 1, n - mid + 1) {
      int t = a[i + mid - 1] - a[i - 1];
      if (t <= k || mid - t <= k) {
        ok = true;
        break;
      }
    }

    if (ok) {
      res = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  cout << res << endl;
}

