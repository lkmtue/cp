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

#define MAX 22
#define MAXT 1000

int n, limit;
double p[MAX];

int sz;
int cache[MAX], pos[MAX], cnt[MAX];

int takeOne() {
  double t = 1.0 * rand() / RAND_MAX;
  double sum = 0;
  FOR (i, 1, n) {
    sum += p[i];
    if (sum + 1e-6 > t) {
      return i;
    }
  }
}

void push(int i) {
  if (pos[i] == 0) {
    if (sz == limit) {
      pos[cache[limit]] = 0;
      FORD (j, limit, 2) {
        cache[j] = cache[j - 1];
        pos[cache[j]] = j;
      }
      cache[1] = i;
      pos[i] = 1;
    } else {
      cache[++sz] = i;
      pos[i] = sz;
    }
  } else {
    FORD (j, pos[i], 2) {
      cache[j] = cache[j - 1];
      pos[cache[j]] = j;
    }
    cache[1] = i;
    pos[i] = 1;
  }
}

int main() {
  while (cin >> n >> limit) {
    FOR (i, 1, n) cin >> p[i];

    int total = 0;
    memset(cnt, 0, sizeof(cnt));

    REP (times, 1e8) {
      memset(cache, 0, sizeof(cache));
      memset(pos, 0, sizeof(pos));
      sz = 0;

      while (sz != limit) {
        int i = takeOne();
        push(i);

        if (sz == limit) {
          FOR (i, 1, n) {
            cnt[cache[i]]++;
          }
          total++;
        }
      }
    }

    FOR (i, 1, n) {
      printf("%.10lf ", 1.0 * cnt[i] / total);
    }
    cout << endl;
  }
}

