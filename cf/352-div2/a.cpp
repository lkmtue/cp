#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  int c = 0;
  int i = 0;
  while (true) {
    string s;
    int x = ++i;
    vector<int> v;
    while (x) {
      v.push_back(x % 10);
      x /= 10;
    }
    reverse(v.begin(), v.end());
    if (c + v.size() >= n) {
      cout << v[n - c - 1] << endl;
      break;
    }
    c += v.size();
  }
}
