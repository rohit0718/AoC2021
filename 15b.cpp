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

void increment(vector<int>& v) {
  for (auto& tmp : v) {
    tmp = (tmp == 9) ? 1 : tmp + 1;
  }
}

void append(int width, vector<int>& v) {
  int sz = v.size();
  for (int i = sz - width; i < sz; ++i) {
    int tmp = (v[i] == 9) ? 1 : v[i] + 1;
    v.push_back(tmp);
  }
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

  vector<vector<int>> expandedV;
  for (int i = 0; i < 5 * v.size(); ++i) {
    vector<int> tmp(v[0].size());
    if (i < v.size()) {
      copy(v[i].begin(), v[i].end(), tmp.begin());
    } else {
      copy(expandedV[i - v.size()].begin(),
          expandedV[i - v.size()].begin() + v[0].size(), tmp.begin());
      increment(tmp);
    }
    for (int j = 0; j < 4; ++j) {
      append(v[0].size(), tmp);
    }
    expandedV.push_back(tmp);
  }

  int n = expandedV.size() * expandedV[0].size();
  vector<vector<ii>> adj(n);
  for (int i = 0; i < expandedV.size(); ++i) {
    for (int j = 0; j < expandedV[0].size(); ++j) {
      int cur = i * expandedV[0].size() + j;
      if (j) {
        adj[cur - 1].push_back({ cur,expandedV[i][j] });
      }
      if (j < expandedV[0].size() - 1) {
        adj[cur + 1].push_back({ cur,expandedV[i][j] });
      }
      if (i) {
        adj[cur - expandedV[0].size()].push_back({ cur,expandedV[i][j] });
      }
      if (i < expandedV.size() - 1) {
        adj[cur + expandedV[0].size()].push_back({ cur,expandedV[i][j] });
      }
    }
  }

  cout << dijkstra(0, adj) << "\n";
}

