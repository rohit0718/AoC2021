#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> ii;

const int INF = 1e9;

int dijkstra(int s, vector<vector<ii>>& adj) {
  int n = adj.size();
  vector<int> dist(n, INF);
  auto comp = [&](ii a, ii b) {
    return a.second > b.second;
  };
  priority_queue<ii,vector<ii>,decltype(comp)> pq(comp);
  dist[s] = 0;
  pq.push({ 0,0 });

  while (pq.size()) {
    auto p = pq.top(); pq.pop();
    int u = p.first;
    int w = p.second;
    if (w > dist[u]) continue;
    for (auto p : adj[u]) {
      int v = p.first;
      int w = p.second;
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        pq.push({ v,dist[v] });
      }
    }
  }

  return dist[n - 1];
}

int main() {
  vector<vector<int>> v;
  string s;
  while (cin >> s) {
    vector<int> tmp;
    for (char& c : s) {
      tmp.push_back(c - '0');
    }
    v.push_back(tmp);
  }

  int n = v.size() * v[0].size();
  vector<vector<ii>> adj(n);
  for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j < v[0].size(); ++j) {
      int cur = i * v[0].size() + j;
      if (j) {
        adj[cur - 1].push_back({ cur,v[i][j] });
      }
      if (j < v[0].size() - 1) {
        adj[cur + 1].push_back({ cur,v[i][j] });
      }
      if (i) {
        adj[cur - v[0].size()].push_back({ cur,v[i][j] });
      }
      if (i < v.size() - 1) {
        adj[cur + v[0].size()].push_back({ cur,v[i][j] });
      }
    }
  }

  cout << dijkstra(0, adj) << "\n";
}

