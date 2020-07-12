#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
  int vertices;
  list<int> *l;
  Graph(int vertices)
  {
    this->vertices = vertices;
    l = new list<int>[vertices];
  }

  void addEdge(int x, int y)
  {
    l[x].push_back(y);
    l[y].push_back(x);
  }

  void printGraph()
  {
    for (int i = 0; i < vertices; i++)
    {
      cout << i << " -> ";
      for (auto nbrs : l[i])
        cout << nbrs << " , ";
      cout << "\n";
    }
  }
};

int main()
{
  Graph obj(5);
  obj.addEdge(1, 2);
  obj.addEdge(2, 3);
  obj.addEdge(3, 4);
  obj.addEdge(4, 1);

  obj.printGraph();
  return 0;
}