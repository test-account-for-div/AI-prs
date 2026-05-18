#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int source;
  int destination;
  int cost;
};

bool compare(Edge a, Edge b) { return a.cost < b.cost; }

int parent[100];

int findParent(int x) {
  if (parent[x] == x) {
    return x;
  }
  return findParent(parent[x]);
}

void unionSet(int a, int b) {
  int pa = findParent(a);
  int pb = findParent(b);

  parent[pa] = pb;
}

int main() {

  int vertices, edges;

  cout << "Enter number of villages: ";
  cin >> vertices;

  cout << "Enter number of pipes: ";
  cin >> edges;

  vector<Edge> graph(edges);

  cout << "Enter source destination and cost:\n";

  for (int i = 0; i < edges; i++) {

    cin >> graph[i].source;
    cin >> graph[i].destination;
    cin >> graph[i].cost;
  }

  for (int i = 0; i < vertices; i++) {
    parent[i] = i;
  }

  sort(graph.begin(), graph.end(), compare);

  int minimumCost = 0;

  cout << "\nMinimum Spanning Tree:\n";

  for (int i = 0; i < edges; i++) {

    int u = graph[i].source;
    int v = graph[i].destination;
    int w = graph[i].cost;

    if (findParent(u) != findParent(v)) {

      cout << u << " - " << v << " : " << w << endl;

      minimumCost = minimumCost + w;

      unionSet(u, v);
    }
  }

  cout << "\nTotal Minimum Cost = " << minimumCost;

  return 0;
}