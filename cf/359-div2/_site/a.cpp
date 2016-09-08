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
  int n;
  ll x;
  cin >> n >> x;
  int d = 0;

  REP (i, n) {
    string s;
    ll num;
    cin >> s >> num;

    if (s == "+") {
      x += num;
    } else {
      if (x >= num) {
        x -= num;
      } else {
        d++;
      }
    }
  }
  cout << x << " " << d << endl;
}

