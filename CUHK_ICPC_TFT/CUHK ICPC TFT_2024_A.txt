CUHK ICPC TFT-2024-A

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  char c;
  cin >> n;
  bool z = 1;
  int cnt = 0;
  if (!n)
    z = 0;
  while (cin >> c) {
    if (c == '+') {
      if (z)
        cnt++;
      cin >> n;
      z = 1;
      if (!n)
        z = 0;
    } else {
      cin >> n;
      if (!n)
        z = 0;
    }
  }
  if (z)
    cnt++;
  cout << cnt << "\n";
  return 0;
}