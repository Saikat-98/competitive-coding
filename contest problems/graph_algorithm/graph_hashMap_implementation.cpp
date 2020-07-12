#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
  int vertices;
  unordered_map<string, list<pair<string, int>>> m;

  Graph(int vertices)
  {
    this->vertices = vertices;
  }

  void addEdge(string x, string y, bool biDirectional, int weight)
  {
    m[x].push_back(make_pair(y, weight));
    if (biDirectional)
      m[y].push_back(make_pair(x, weight));
  }

  void printGraph()
  {
    for (auto i : m)
    {
      string city = i.first;
      cout << city << " -> ";
      list<pair<string, int>> nbrs = i.second;
      for (auto j : nbrs)
        cout << "Edge: " << j.first << " Weight: " << j.second << " , ";
      cout << "\n";
    }
  }
};

int main()
{
  Graph obj(4);
  obj.addEdge("A", "B", true, 20);
  obj.addEdge("B", "C", true, 40);
  obj.addEdge("C", "D", true, 60);
  obj.addEdge("D", "A", false, 80);

  obj.printGraph();
  return 0;
}