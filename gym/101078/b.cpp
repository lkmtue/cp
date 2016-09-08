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

#define MAX 50111

int a[MAX];
int f[MAX];

int main() {
  int numt;
  cin >> numt;
  REP (_, numt) {
    int n, m, cut, dj;
    cin >> n >> m >> cut >> dj;
    FOR (i, 1, n) cin >> a[i];

    f[0] = 0;

    FOR (i, 1, n) {
      int sum = 0;
      int j = i;
      f[i] = 1e9;
      while (j >= 1 && sum <= 300) {
        sum += a[j];
        int cost = 0;

        if (sum < m) {
          cost = (m - sum) * dj;
        } else if (sum > m) {
          cost = (sum - m) * cut;
        }

        f[i] = min(f[i], f[j - 1] + cost);
        j--;
      }
    }

    cout << f[n] << endl;
  }
}

