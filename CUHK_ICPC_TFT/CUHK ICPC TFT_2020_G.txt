CUHK ICPC TFT-2020-G

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<double> vi;
typedef stack<double> si;

ll d[100010]; // d[i]=a[i+2]-a[i]=b[i+1]-b[i]
ll s1[50010]; // s1[i]=a[i]-a[0]=d[i-2]+d[i-4]+...+d[0]=s1[i-2]+d[i-2] for even
              // i
ll s2[50010]; // s2[i]=a[i]-a[1]=d[i-2]+d[i-4]+...+d[1]=s2[i-2]+d[i-2] for odd i

int main() {
  int n;
  ll sum = 0, evensum = 0;
  bool z;
  cin >> n;
  int b[100010], c[100010];
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    sum += b[i];
    if (!(i % 2))
      evensum += b[i];
  }
  for (int i = 0; i < n; i++)
    d[i] = b[(i + 1) % n] - b[i];
  s1[2] = b[1] - b[0];
  for (int i = 4; i < n; i += 2)
    s1[i] = s1[i - 2] + d[i - 2];
  s2[3] = b[2] - b[1];
  for (int i = 5; i < n; i += 2)
    s2[i] = s2[i - 2] + d[i - 2];
  if (n % 2) {
    if (sum % 2)
      cout << "No\n";
    else {
      sum /= 2;
      for (int i = 1; i < n; i += 2)
        sum -= b[i];
      z = 1;
      c[0] = sum;
      if (!c[0])
        z = 0;
      for (int i = 1; i < n; i++) {
        c[i] = b[i - 1] - c[i - 1];
        if (c[i] <= 0)
          z = 0;
      }
      if (z) {
        cout << "Yes\n";
        for (int i = 0; i < n - 1; i++)
          cout << c[i] << " ";
        cout << c[n - 1] << "\n";
      } else
        cout << "No\n";
    }
  } else {
    if (evensum * 2 != sum)
      cout << "No\n";
    else {
      ll mins1 = 1e15, mins2 = 1e15;
      for (int i = 2; i < n; i += 2)
        mins1 = min(mins1, s1[i]);
      for (int i = 3; i < n; i += 2)
        mins2 = min(mins2, s2[i]);
      z = 1;
      c[0] = (1 - mins1 > 1) ? 1 - mins1 : 1;
      // choose c[0] such that c[0]+s1[i]>=1 for all even i
      for (int i = 1; i < n; i++) {
        c[i] = b[i - 1] - c[i - 1];
        if (c[i] <= 0)
          z = 0;
      }
      if (z) {
        cout << "Yes\n";
        for (int i = 0; i < n - 1; i++)
          cout << c[i] << " ";
        cout << c[n - 1] << "\n";
        return 0;
      }
      z = 1;
      c[1] = (1 - mins2 > 1) ? 1 - mins2 : 1;
      for (int i = 2; i < n + 1; i++) {
        c[i % n] = b[i - 1] - c[i - 1];
        if (c[i % n] <= 0)
          z = 0;
      }
      if (z) {
        cout << "Yes\n";
        for (int i = 0; i < n - 1; i++)
          cout << c[i] << " ";
        cout << c[n - 1] << "\n";
        return 0;
      }
      cout << "No\n";
    }
  }
  return 0;
}