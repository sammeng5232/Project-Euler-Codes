CUHK ICPC TFT-2021-C

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<double> vi;
typedef stack<double> si;

const int md = 1e9 + 7;
int n, k, a[100010], len[100010], t;
ll dp[110][100010];
map<int, int> b;

int main() {
  cin >> n >> k;
  for (int l = 1, r; l <= k; l = r + 1) {
    r = min(k / (k / l), k);
    a[++t] = r;
    b[r] = t;
    len[t] = r - l + 1;
  }
  for (int i = 1; i <= t; i++)
    dp[0][i] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= t; j++)
      dp[i][j] = (dp[i][j - 1] + (ll)len[j] * dp[i - 1][b[k / a[j]]]) % md;
  cout << dp[n][t] << "\n";
  return 0;
}