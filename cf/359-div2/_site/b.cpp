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

#define MAX 111
int a[MAX];

int main() {
  int n;
  cin >> n;
  REP (i, n) {
    cin >> a[i];
  }

  REP (i, n) {
    int k = i;

    FOR (j, i, n - 1) {
      if (a[j] < a[k]) k = j;
    }

    FORD (j, k, i + 1) {
      cout << j << " " << j + 1 << endl;
      swap(a[j - 1], a[j]);
    }
  }
}

