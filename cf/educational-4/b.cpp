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

int r[255];

int main() {
  r['A'] = 'A';
  r['b'] = 'd';
  r['d'] = 'b';
  r['H'] = 'H';
  r['I'] = 'I';
  r['M'] = 'M';
  r['O'] = 'O';
  r['o'] = 'o';
  r['p'] = 'q';
  r['q'] = 'p';
  r['T'] = 'T';
  r['U'] = 'U';
  r['V'] = 'V';
  r['v'] = 'v';
  r['W'] = 'W';
  r['w'] = 'w';
  r['X'] = 'X';
  r['x'] = 'x';
  r['Y'] = 'Y';

  string s;
  while (cin >> s) {
    int n = s.size();

    bool ok = true;

    REP (i, n) {
      if (r[s[i]] != s[n - 1 - i]) {
        ok = false;
      }
    }

    cout << (ok ? "TAK" : "NIE") << endl;
  }
}

