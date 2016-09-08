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

#define MAX 1111

int a[MAX];
bool isPrime[MAX];
vector<int> primes;
int primeId[MAX];
vector<int> list[MAX];
int id[MAX];

void initPrimes() {
  memset(isPrime, true, sizeof(isPrime));
  isPrime[1] = false;
  int cnt = 0;
  FOR (i, 2, 1000) {
    if (isPrime[i]) {
      primes.push_back(i);
      primeId[i] = cnt++;
      int j = i + i;
      while (j <= 1000) {
        isPrime[j] = false;
        j += i;
      }
    }
  }
}

bool cmp(int i, int j) {
  int x = list[i][(int)list[i].size() - 1];
  int y = list[j][(int)list[j].size() - 1];
  return x < y;
}

void factorize(int x, vector<int> &list) {
  REP (j, primes.size()) {
    int p = primes[j];
    if (p > x) break;
    if (x % p == 0) list.push_back(p);
    while (x % p == 0) x /= p;
  }
}

int f[MAX][MAX];

int main() {
  int t;
  cin >> t;

  initPrimes();

  vector<int> temp;

  while (t--) {
    int n;
    cin >> n;

    int res = 0;
    int m = 0;
    FOR (j, 1, n) {
      int x;
      cin >> x;

      if (x == 1) {
        res++;
        continue;
      }

      a[++m] = x;
    }

    n = m;

    FOR (i, 1, n) {
      list[i].clear();
      factorize(a[i], list[i]);

      id[i] = i;

      //REP (j, list[i].size()) cout << list[i][j] << " ";
      //cout << endl;
    }
    sort(id + 1, id + n + 1, cmp);

    int j = -1;
    int lastP = 0;

    int best = 0;

    REP (s, 1 << 10) f[0][s] = -1;
    f[0][0] = 0;

    FOR (i, 1, n) {
      vector<int> &l = list[id[i]];
      if (l[(int)l.size() - 1] != lastP) {
        j = i - 1;
        lastP = l[(int)l.size() - 1];
      }

      // Calc mask.
      int x = a[id[i]];
      int mask = 0;
      REP (k, l.size()) {
        int p = l[k];
        if (primeId[p] < 10) {
          mask += 1 << primeId[p];
        }
      }

      // Update dp.
      REP (s, 1 << 10) {
        f[i][s] = f[i - 1][s];
        // use i.
        if ((s | mask) == s && f[j][s ^ mask] != -1) {
          f[i][s] = max(f[i][s], f[j][s ^ mask] + 1);
        }
        best = max(best, f[i][s]);
      }
    }

    res += best;
    cout << res << endl;
  }
}

