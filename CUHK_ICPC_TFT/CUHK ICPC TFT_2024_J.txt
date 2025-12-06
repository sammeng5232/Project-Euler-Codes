CUHK ICPC TFT-2024-J

Code 1:
#include <bits/stdc++.h>
using namespace std;

int n, m, s[2010], t[2010];
long long dp[2010][2010], dp2[2010][2010], ps[2010][2010], md = 1e9 + 7;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> s[i];
  for (int j = 1; j <= m; j++)
    cin >> t[j];
  /*dp[1][1]=1+(s[1]==t[1]);
  for(int j=2;j<=m;j++)dp[1][j]=(dp[1][j-1]+(s[1]==t[j]))%md;
  for(int i=2;i<=n;i++)dp[i][1]=(dp[i-1][1]+(s[i]==t[1]))%md;
  for(int i=2;i<=n;i++)for(int j=2;j<=m;j++){
      if(s[i]==t[j])dp[i][j]=(dp[i-1][j]+dp[i][j-1])%md;
      if(s[i]!=t[j])dp[i][j]=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1])%md;
  }
  cout<<dp[n][m]<<"\n";*/
  ps[0][0] = dp2[0][0] = 1;
  dp2[1][1] = (s[1] == t[1]);
  ps[1][1] = ps[0][0] + dp2[1][1];
  for (int j = 2; j <= m; j++) {
    dp2[1][j] = (s[1] == t[j]);
    ps[1][j] = ps[1][j - 1] + dp2[1][j];
  }
  for (int i = 2; i <= n; i++) {
    dp2[i][1] = (s[i] == t[1]);
    ps[i][1] = ps[i - 1][1] + dp2[i][1];
  }
  for (int i = 2; i <= n; i++)
    for (int j = 2; j <= m; j++) {
      if (s[i] == t[j])
        dp2[i][j] = ps[i - 1][j - 1];
      ps[i][j] =
          (((ps[i - 1][j] + ps[i][j - 1]) % md + md - ps[i - 1][j - 1]) % md +
           dp2[i][j]) %
          md;
    }
  cout << ps[n][m] << "\n";
  // for(int i=0;i<=n;i++){for(int j=0;j<=m;j++)cout<<ps[i][j]<<" ";cout<<"\n";}
  return 0;
}

Code 2:
#include <bits/stdc++.h>
using namespace std;

int n, m, s[2010], t[2010];
long long dp[2010][2010], md = 1e9 + 7;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> s[i];
  for (int j = 1; j <= m; j++)
    cin >> t[j];
  dp[1][1] = 1 + (s[1] == t[1]);
  for (int j = 2; j <= m; j++)
    dp[1][j] = (dp[1][j - 1] + (s[1] == t[j])) % md;
  for (int i = 2; i <= n; i++)
    dp[i][1] = (dp[i - 1][1] + (s[i] == t[1])) % md;
  for (int i = 2; i <= n; i++)
    for (int j = 2; j <= m; j++) {
      if (s[i] == t[j])
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % md;
      if (s[i] != t[j])
        dp[i][j] =
            ((dp[i - 1][j] + dp[i][j - 1]) % md + md - dp[i - 1][j - 1]) % md;
    }
  cout << dp[n][m] << "\n";
  return 0;
}