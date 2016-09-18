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

#define MAX 600111

int a[MAX];
int b[MAX];

int main() {
  int n, k;
  cin >> n >> k;
  FOR (i, 1, k) {
    scanf("%d", &a[i]);
    b[a[i]] = i;
  }
  FOR (i, 1, k) {
    int x = a[i] + a[i];

    while (x <= n) {
      if (b[x]) {
        cout << b[x] << " " << i << endl;
        return 0;
      }
      x += a[i];
    }
  }
  cout << "0 0" << endl;
}

