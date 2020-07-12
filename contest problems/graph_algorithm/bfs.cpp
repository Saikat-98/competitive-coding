#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
  map<T, list<T>> m;

public:
  void addEdge(int x, int y)
  {
    m[x].push_back(y);
    m[y].push_back(x);
  }

  void bfs(T src)
  {
    map<T, bool> visited;
    queue<T> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
      T temp = q.front();
      q.pop();
      cout << temp << " ";
      for (auto nbrs : m[temp])
        if (!visited[nbrs])
        {
          q.push(nbrs);
          visited[nbrs] = true;
        }
    }
  }
};

int main()
{
  Graph<int> g;
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 4);
  g.addEdge(4, 5);

  g.bfs(0);
  return 0;
}