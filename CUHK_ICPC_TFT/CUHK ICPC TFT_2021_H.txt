CUHK ICPC TFT-2021-H

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<double> vi;
typedef stack<double> si;

int n, p[21], d, i1, i2, i3, i4, k, b[21], minp, currp;
int need[21], bought[21];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> p[i];
  cin >> d >> i1 >> i2 >> i3 >> i4 >> k;
  for (int i = 1; i <= k; i++) {
    cin >> b[i];
    need[b[i]]++;
    minp += p[b[i]];
  }
  for (int pset = 1; pset <= 20; pset++) {
    bought[i1] = pset;
    bought[i2] = pset;
    bought[i3] = pset;
    bought[i4] = pset;
    currp = pset * d;
    for (int i = 1; i <= n; i++)
      if (bought[i] < need[i])
        currp += (need[i] - bought[i]) * p[i];
    minp = min(minp, currp);
  }
  cout << minp << '\n';
  return 0;
}