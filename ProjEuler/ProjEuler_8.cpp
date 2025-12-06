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

string s;

ll prod(int p) {
  ll k = 1;
  for (int i = p; i < p + 13; i++)
    k *= (int)s[i] - 48;
  return k;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  int l = s.length();
  int mxpos = 0;
  ll mxprod = 1;
  for (int j = 0; j + 12 < l; j++) {
    if (mxprod < prod(j)) {
      mxprod = prod(j);
      mxpos = j;
    }
  }
  cout << mxprod << "\n";
  return 0;
}
