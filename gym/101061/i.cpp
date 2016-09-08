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

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s1, s2;
    cin >> s1 >> s2;
    map<char, int> c;
    REP (i, s1.size()) {
      c[s1[i]]++;
      c[s2[i]]--;
    }
    ll res = 0;
    for (auto p : c) {
      if (t == 0) {
        cout << p.first << " " << p.second << endl;
      }
      res += abs(p.second);
    }
    cout << res << endl;
  }
}

