#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
  int numt;
  cin >> numt;
  for (int t = 0; t < numt; t++) {
    int n;
    cin >> n;
    vector<pair<string, string> > a;

    for (int i = 0; i < n; i++) {
      string s, t;
      cin >> s >> t;
      a.push_back(make_pair(s, t));
    }

    sort(a.begin(), a.end());

    set<string> z;

    for (int i = 0; i < n; i++) {
      if (i > 0 && a[i].first != a[i - 1].first) {
        int j = i;
        while (j < n && a[j].first == a[i].first) {
          if (z.find(a[j].second) == z.end()) {
            swap(a[i], a[j]);
            break;
          }
          j++;
        }
      }

      z.insert(a[i].second);
    }

    set<string> x, y;

    int res = 0;

    for (int i = 0; i < n; i++) {
      // cout << a[i].first << " " << a[i].second << endl;
      if (x.find(a[i].first) != x.end() && y.find(a[i].second) != y.end()) {
        res++;
      }

      x.insert(a[i].first);
      y.insert(a[i].second);
    }
    cout << "Case #" << t + 1 << ": " << res << endl;
  }
}
