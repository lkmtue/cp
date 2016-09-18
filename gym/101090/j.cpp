#include <algorithm>
#include <cmath>
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
  cin >> n;
  ll odd = n / 2 + n % 2;
  ll even = n / 2;

  ll eee = even * (even - 1) * (even - 2) / 6;
  ll eoo = even * odd * (odd - 1) / 2;
  
  cout << eee + eoo << endl;
}

