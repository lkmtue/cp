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
  int n;
  cin >> n;
  multiset<int> s;
  vector<pair<string, int> > res;

  REP (i, n) {
    string cmd;
    cin >> cmd;
    int x;

    if (cmd == "removeMin") {
      if (s.empty()) {
        res.push_back(make_pair("insert", 0));
        s.insert(0);
      }
      s.erase(s.begin());
    }
    
    if (cmd == "insert") {
      cin >> x;
      s.insert(x);
    }

    if (cmd == "getMin") {
      cin >> x;
      while (!s.empty() && *s.begin() < x) {
        res.push_back(make_pair("removeMin", 0));
        s.erase(s.begin());
      }
      if (s.empty() || *s.begin() > x) {
        res.push_back(make_pair("insert", x));
        s.insert(x);
      }
    }

    res.push_back(make_pair(cmd, x));
  }
  cout << res.size() << endl;
  REP (i, res.size()) {
    cout << res[i].first << " ";
    if (res[i].first != "removeMin") {
      cout << res[i].second;
    }
    cout << endl;
  }
}

