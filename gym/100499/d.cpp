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

#define MAX 1000111

bool prime[MAX];
int f[MAX];

int main() {
  int numt;
  cin >> numt;

  int m = 1000000;

  memset(prime, true, sizeof(prime));

  FOR (i, 2, m) {
    if (prime[i]) {
      int j = i + i;
      while (j <= m) {
        prime[j] = false;
        j += i;
      }
    }
  }

  f[1] = 1;
  FOR (i, 2, m) {
    f[i] = f[i - 1] + (prime[i] ? 1 : 0);
  }

  FOR (test, 1, numt) {
    int n;
    cin >> n;
    cout << "Case #" << test << ": " << f[n] << endl;
  }
}

