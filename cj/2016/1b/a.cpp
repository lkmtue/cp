#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int numt;
  cin >> numt;
  for (int t = 0; t < numt; t++) {
    string s;
    cin >> s;
    vector<int> c(300, 0);
    for (int i = 0; i < s.size(); i++) {
      c[s[i]]++;
    }

    vector<int> r(20, 0);
    r[0] = c['Z'];
    r[6] = c['X'];
    r[2] = c['W'];
    r[8] = c['G'];
    r[3] = c['H'] - r[8];
    r[4] = c['R'] - r[0] - r[3];
    r[5] = c['F'] - r[4];
    r[7] = c['S'] - r[6];
    r[9] = c['I'] - r[5] - r[6] - r[8];
    r[1] = c['O'] - r[0] - r[2] - r[4];

    cout << "Case #" << t + 1 << ": ";
    for (int i = 0; i <= 9; i++) {
      for (int j = 0; j < r[i]; j++) {
        cout << i;
      }
    }
    cout << endl;
  }

}
