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

int n, r, p, s;
char res[5000];
int cnt[3], need[3];
int c;

char ch[] = {'S', 'P', 'R'};

void attempt(int r, int w) {
  if (r == n) {
    res[c++] = ch[w];
    cnt[w]++;
    return;
  } else {
    int l = (w + 1) % 3;
    attempt(r + 1, w);
    attempt(r + 1, l);
  }
}

string get(int l, int r) {
  if (l == r) {
    string s = "";
    s += res[l];
    return s;
  }
  int m = (l + r) / 2;

  string s1 = get(l, m);
  string s2 = get(m + 1, r);

  if (s1 < s2) {
    return s1 + s2;
  } else {
    return s2 + s1;
  }

}

void solve() {
  FOR (i, 0, 2) {
    cnt[0] = 0; cnt[1] = 0; cnt[2] = 0;
    c = 0;
    attempt(0, i);

    bool ok = need[0] == cnt[0] && need[1] == cnt[1] && need[2] == cnt[2];

    if (ok) {
      cout << get(0, (1 << n) - 1);
      return;
    }
  }

  cout << "IMPOSSIBLE";
}

int main() {
  int numt;
  cin >> numt;
  FOR (test, 1, numt) {
    cout << "Case #" << test << ": ";

    cin >> n >> need[2] >> need[1] >> need[0];
    solve();

    cout << endl;
  }
}

