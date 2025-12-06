CUHK ICPC TFT-2021-G

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<double> vi;
typedef stack<double> si;

int main() {
  int n;
  cin >> n;
  int a[100010];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n, greater<int>());
  ll sum = 0;
  for (int i = 0; i < n; i++)
    if (i % 3 != 2)
      sum += a[i];
  cout << sum << "\n";
  return 0;
}