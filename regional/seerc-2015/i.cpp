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

int cnt[50][2000];

int main() {
  int n, k, val;
  scanf("%d%d", &n, &k);

  REP (i, n) {
    scanf("%d", &val);
    int j = 0;
    while (val) {
      cnt[j++][val % k]++;
      val /= k;
    }
  }

  int res = 0;
  FORD (i, 40, 0) {
    res *= k;
    REP (j, k) {
      if (cnt[i][j] % k != 0) {
        res += j;
        break;
      }
    }
  }

  cout<< res;
}

