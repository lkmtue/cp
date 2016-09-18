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
  int numt;
  cin >> numt;
  while (numt--) {
    int n;
    cin >> n;
    FOR (i, 1, 2 * n + 1) {
      FOR (j, 1, 2 * n + 1) {
        int x = abs(i - n - 1);
        int y = abs(j - n - 1);
        printf("%c", (x + y) % 3 ? 'w' : 'b');
      }
      printf("\n");
    }
  }
}

