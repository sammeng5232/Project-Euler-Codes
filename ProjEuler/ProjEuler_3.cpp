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

ll n;

ll largestpf(ll k) {
  ll p = 1;
  ll r = k;
  for (ll i = 2; i <= k; i++) {
    while (k % i == 0) {
      p = i;
      k /= i;
    }
  }
  return p;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  cout << largestpf(n) << "\n";
  return 0;
}