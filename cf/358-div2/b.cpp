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

#define MAX 100111

int a[MAX];

int main() {
  int n;
  while (cin >> n) {
    FOR (i, 1, n) {
      cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    int x = 0;
    FOR (i, 1, n) {
      x++;
      x = min(x, a[i]);
    }

    cout << x + 1 << endl;
  }
}

