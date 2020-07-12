#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define setbits(x) __builtin_popcountll(x)
#define tz(x) __builtin_ctzll(x)
#define lz(x) __builtin_clzll(x)
#define fsetbit(x) ffsll(x)
#define mod 1000000007
#define inf 1e18
#define w(x) \
  int x;     \
  cin >> x;  \
  while (x--)
#define debug(x, val) cout << "The value of " << x << " is: " << val << "\n";
#define op(x) cout << x << "\n";
void fastIO()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

bool ratInMaze(char maze[10][10], int soln[][10], int i, int j, int m, int n)
{
  //Base Case
  if (i == m && j == n)
  {
    soln[m][n] = 1;

    //Print the path
    cout << "\n";
    for (int i = 0; i <= m; i++)
    {
      for (j = 0; j <= n; j++)
        cout << soln[i][j] << " ";
      cout << "\n";
    }

    return true;
  }

  // Rat should be inside grid
  if (i > m || j > n)
    return false;

  if (maze[i][j] == 'X')
    return false;

  // Assume solution exists through current cell
  soln[i][j] = 1;
  bool rightSuccess = ratInMaze(maze, soln, i, j + 1, m, n);
  bool downSuccess = ratInMaze(maze, soln, i + 1, j, m, n);

  //Backtracking
  soln[i][j] = 0;

  if (rightSuccess || downSuccess)
    return true;
  return false;
}

int main()
{
  fastIO();

  char maze[10][10] = {
      "0000", "00X0", "000X", "0X00"};

  int soln[10][10] = {0};
  int m = 4, n = 4;

  bool ans = ratInMaze(maze, soln, 0, 0, m - 1, n - 1);
  if (ans == false)
    cout << "Path doesn't exist";

  return 0;
}