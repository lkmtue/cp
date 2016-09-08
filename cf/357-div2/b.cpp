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
  ll n;
  cin >> n;
  REP (i, 1000) REP (j, 10000) {
    ll x = 1234567LL * i + 123456LL * j;
    if (x <= n && (n - x) % 1234 == 0) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}

