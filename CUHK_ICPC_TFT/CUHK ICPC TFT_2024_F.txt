CUHK ICPC TFT-2024-F

#include <bits/stdc++.h>
using namespace std;

int n, u, v, w, deg[100010], dist[100010];
bool vis[100010];
queue<int> q;
vector<int> adj1[100010]; // neighbours
vector<int> adj2[100010]; // lengths

int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> u >> v >> w;
    w %= 2;
    adj1[u].push_back(v);
    adj1[v].push_back(u);
    adj2[u].push_back(w);
    adj2[v].push_back(w);
    deg[u]++;
    deg[v]++;
  }
  q.push(1);
  vis[1] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i < deg[x]; i++)
      if (!vis[adj1[x][i]]) {
        q.push(adj1[x][i]);
        vis[adj1[x][i]] = 1;
        dist[adj1[x][i]] = dist[x] + adj2[x][i];
      }
  } /*
   for(int i=1;i<=n;i++){
       cout<<i<<" ";
       for(int j=0;j<deg[i];j++)
           cout<<adj1[i][j]<<" "<<adj2[i][j]<<" ";
       cout<<"\n";
   }
   for(int i=1;i<=n;i++)cout<<deg[i]<<"\n";*/
  for (int i = 1; i <= n; i++)
    cout << dist[i] % 2 << "\n";
  return 0;
}