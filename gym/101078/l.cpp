#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORN(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define BUG(x) cerr << #x << " = " << x << endl

int main() {
  string s;
  cin >> s;
  double res = 0;
  int j = (int)s.size() - 1;
  REP (i, s.size()) {
    if (s[i] == '1') {
      while (j > i && s[j] == '1') j--;
      if (i >= j) break;
      s[i] = '0';
      s[j] = '1';
      res += sqrt(j - i);
    }
  }
  printf("%.10lf\n", res);
}

