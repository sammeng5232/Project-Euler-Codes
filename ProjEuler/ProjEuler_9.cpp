#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef stack<ll> sl;
typedef stack<int> si;
typedef queue<ll> ql;
typedef queue<int> qi;
typedef map<int, int> mii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (ll i = 1; i <= 1000; i++)
    for (ll j = i; j <= 1000; j++)
      if (i * i + j * j == (1000 - i - j) * (1000 - i - j))
        cout << i * j * (1000 - i - j) << "\n";
  return 0;
}
