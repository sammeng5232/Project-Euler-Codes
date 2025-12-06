CUHK ICPC TFT-2024-D

#include <bits/stdc++.h>
using namespace std;

int n, m, id;
long long ans, a, b, c;

struct Card {
  long long num, cnt;
} s[200010];

bool cmp(Card x, Card y) { return x.num > y.num; }

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a;
    s[i].num = a;
    s[i].cnt = 1;
  }
  for (int i = 0; i < m; i++) {
    cin >> b >> c;
    s[n + i].num = c;
    s[n + i].cnt = b;
  }
  sort(s, s + n + m, cmp);
  // for(int i=0;i<n+m;i++)cout<<s[i].num<<" "<<s[i].cnt<<"\n";
  id = 0;
  while (n > 0) {
    if (n >= s[id].cnt) {
      ans += s[id].num * s[id].cnt;
      n -= s[id].cnt;
      id++;
    } else {
      ans += s[id].num * n;
      n = 0;
    }
  }
  cout << ans << "\n";
  return 0;
}