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

#define MAX 15

int n;
double p[MAX][MAX];

int a[MAX];

bool used[MAX];
double res;

void gen(int x) {
  if (x > n) {
    double d = 1;
    FOR (i, 1, n) {
      FOR (j, i + 1, n) {
        d *= p[a[i]][a[j]];
      }
    }
    res += d;
    return;
  }
  FOR (i, 1, n) {
    if (!used[i]) {
      used[i] = true;
      a[x] = i;
      gen(x + 1);
      used[i] = false;
    }
  }
}

double fac(int n) {
  if (n == 0) return 1;
  else return fac(n - 1) * n;
}

int main() {
  cin >> n;
  FOR (i, 1, n) {
    FOR (j, 1, n) {
      cin >> p[i][j];
    }
  }
  gen(1);
  printf("%.10lf\n", res);
}

