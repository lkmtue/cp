#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

int a[100111];

int main() {
  ios::sync_with_stdio(false);
  int n, q;

  cin >> n >> q;
  set<pair<int, int> > table;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    table.insert(make_pair(a[i], i));
  }

  for (int i = 0; i < q; i++) {
    string s;
    int x;
    cin >> s >> x;

    if (s == "in") {
      set<pair<int, int > >::iterator it = table.lower_bound(make_pair(x, -1));
      if (it != table.end()) {
        cout << it->second << endl;
        table.erase(it);
      } else {
        cout << -1 << endl;
      }
    } else {
      table.insert(make_pair(a[x], x));
    }
  }
}
