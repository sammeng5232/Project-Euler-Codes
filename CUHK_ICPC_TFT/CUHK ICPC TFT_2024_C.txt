CUHK ICPC TFT-2024-C

Code 1:
#include <bits/stdc++.h>
using namespace std;

int n;
int a[300010];
long long mxsubarray[300010], minsubarray[300010], ans = -1e16;
priority_queue<int, vector<int>, greater<int>> q;
int heap[300010];
int len = 0;

void push2(int x) {
  heap[++len] = x;
  int j = len;
  while (j > 1 && heap[j] > heap[j / 2]) {
    swap(heap[j], heap[j / 2]);
    j /= 2;
  }
}

void pop2() {
  heap[1] = heap[len--];
  int j = 1;
  while (2 * j <= len) {
    int s = 2 * j;
    if (s < len && heap[s + 1] > heap[s])
      s++;
    if (heap[s] > heap[j]) {
      swap(heap[s], heap[j]);
      j = s;
    } else
      break;
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= 3 * n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++) {
    mxsubarray[n] += a[i];
    q.push(a[i]);
  }
  for (int i = n + 1; i <= 2 * n; i++) {
    mxsubarray[i] = mxsubarray[i - 1];
    if (a[i] > q.top()) {
      mxsubarray[i] += a[i] - q.top();
      q.pop();
      q.push(a[i]);
    }
  }
  // for(int i=n;i<=2*n;i++)cout<<mxsubarray[i]<<" ";cout<<"\n";
  for (int i = 3 * n; i >= 2 * n + 1; i--) {
    minsubarray[2 * n + 1] += a[i];
    push2(a[i]);
  }
  for (int i = 2 * n; i > n; i--) {
    minsubarray[i] = minsubarray[i + 1];
    if (a[i] < heap[1]) {
      minsubarray[i] += a[i] - heap[1];
      pop2();
      push2(a[i]);
    }
  }
  // for(int i=n+1;i<=2*n+1;i++)cout<<minsubarray[i]<<" ";cout<<"\n";
  for (int i = n; i <= 2 * n; i++)
    ans = max(ans, mxsubarray[i] - minsubarray[i + 1]);
  cout << ans << "\n";
  return 0;
}

Code 2:
#include <bits/stdc++.h>
using namespace std;

int n;
int a[300010];
long long mxsubarray[300010], minsubarray[300010], ans = -1e16;
priority_queue<int, vector<int>, greater<int>> q;
priority_queue<int, vector<int>> q2;
int len = 0;

int main() {
  cin >> n;
  for (int i = 1; i <= 3 * n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++) {
    mxsubarray[n] += a[i];
    q.push(a[i]);
  }
  for (int i = n + 1; i <= 2 * n; i++) {
    mxsubarray[i] = mxsubarray[i - 1];
    if (a[i] > q.top()) {
      mxsubarray[i] += a[i] - q.top();
      q.pop();
      q.push(a[i]);
    }
  }
  // for(int i=n;i<=2*n;i++)cout<<mxsubarray[i]<<" ";cout<<"\n";
  for (int i = 3 * n; i >= 2 * n + 1; i--) {
    minsubarray[2 * n + 1] += a[i];
    q2.push(a[i]);
  }
  for (int i = 2 * n; i > n; i--) {
    minsubarray[i] = minsubarray[i + 1];
    if (a[i] < q2.top()) {
      minsubarray[i] += a[i] - q2.top();
      q2.pop();
      q2.push(a[i]);
    }
  }
  // for(int i=n+1;i<=2*n+1;i++)cout<<minsubarray[i]<<" ";cout<<"\n";
  for (int i = n; i <= 2 * n; i++)
    ans = max(ans, mxsubarray[i] - minsubarray[i + 1]);
  cout << ans << "\n";
  return 0;
}
