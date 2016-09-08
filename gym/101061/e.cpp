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

int nxt[MAX][10];

string solve(string s, int n, int delta) {
  int l = s.size();
  s = " " + s;

  FOR (d, 0, 9) nxt[l + 1][d] = l + 1;

  FORD (i, l, 1) {
    FOR (d, 0, 9) {
      nxt[i][d] = nxt[i + 1][d];
    }
    nxt[i][s[i] - 48] = i;
  }

  int i = 1;
  int remain = n;

  string res = "";

  while (true) {
    for (int d = delta == 1 ? 0 : 9; 0 <= d && d <= 9; d += delta) {
      int j = nxt[i][d];
      if (j > l) continue;
      int nRemove = j - i;
      if (nRemove > remain) continue; 

      remain -= nRemove;

      res += char(d + 48);
      i = j + 1;
      break;
    }
    if (res.size() == l - n) {
      break;
    }
  }

  return res;
}

int main() {
  int _;
  cin >> _;
  while (_--) {
    string s;
    int n;
    cin >> s >> n;
    cout << solve(s, n, 1) << endl;
    cout << solve(s, n, -1) << endl;
  }
}

