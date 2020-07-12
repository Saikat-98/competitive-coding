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

bool isSafe(int board[][10], int i, int j, int n)
{
  // Current Column
  for (int row = 0; row < i; row++)
  {
    if (board[row][j] == 1)
      return false;
  }

  // Left diagonal
  int x = i;
  int y = j;
  while (x >= 0 && y >= 0)
  {
    if (board[x][y] == 1)
      return false;
    x--;
    y--;
  }

  // Right diagonal
  x = i;
  y = j;
  while (x >= 0 && y < n)
  {
    if (board[x][y] == 1)
      return false;
    x--;
    y++;
  }

  return true;
}

bool nQueenSolver(int board[][10], int i, int n)
{
  //Base Case
  if (i == n)
  {
    //Print the board
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        if (board[i][j] == 1)
          cout << "Q ";
        else
          cout << "_ ";
      cout << '\n';
    }
    // To get first configuartion
    // return true;
    cout << "\n";
    // To get all possible configurations
    return false;
  }

  // Recursive case
  // Try to put the queen in the current row and call for the remaining part
  for (int j = 0; j < n; j++)
  {
    if (isSafe(board, i, j, n))
    {
      board[i][j] = 1;
      bool rest = nQueenSolver(board, i + 1, n);
      if (rest)
        return true;
      board[i][j] = 0;
    }
  }

  return false;
}

int main()
{
  fastIO();
  int board[10][10] = {0};
  int n;
  cin >> n;

  nQueenSolver(board, 0, n);
  return 0;
}