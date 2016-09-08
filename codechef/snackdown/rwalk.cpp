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
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    REP (i, n) {
      int x; char ch;
      cin >> x >> ch;
      if (i % 2 == 0) a.push_back(x);
      else b.push_back(x);
    }
    
  }
}

