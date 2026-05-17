#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int u, v, weight;
};

class DSU {
  vector<int> parent, rank;

public:
  DSU(int n) {
    parent.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 0;
    }
  }

  int find(int x) {
    if (parent[x] != x)
      parent[x] = find(parent[x]);
    return parent[x];
  }

  void unite(int x, int y) {
    int px = find(x);
    int py = find(y);

    if (px == py)
      return;

    if (rank[px] < rank[py])
      parent[px] = py;
    else if (rank[px] > rank[py])
      parent[py] = px;
    else {
      parent[py] = px;
      rank[px]++;
    }
  }
};

bool cmp(Edge a, Edge b) { return a.weight < b.weight; }

int main() {
  int V, E;
  cout << "Enter number of villages: ";
  cin >> V;

  cout << "Enter number of pipes: ";
  cin >> E;

  vector<Edge> edges(E);

  cout << "Enter edges (u v cost):\n";
  for (int i = 0; i < E; i++) {
    cin >> edges[i].u >> edges[i].v >> edges[i].weight;
  }

  sort(edges.begin(), edges.end(), cmp);

  DSU dsu(V);

  int totalCost = 0;

  cout << "\nMinimum Cost Pipe Network:\n";

  for (int i = 0; i < edges.size(); i++) {
    Edge edge = edges[i];

    if (dsu.find(edge.u) != dsu.find(edge.v)) {
      cout << edge.u << " -- " << edge.v << "  Cost: " << edge.weight << endl;

      totalCost += edge.weight;
      dsu.unite(edge.u, edge.v);
    }
  }

  cout << "\nTotal Minimum Cost: " << totalCost << endl;

  return 0;
}
