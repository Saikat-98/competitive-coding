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

bool isSafe(int mat[][9], int i, int j, int n, int number)
{
  // Row and column check
  for (int row = 0; row < n; row++)
    if (mat[i][row] == number || mat[row][j] == number)
      return false;

  // Grid check
  int rn = sqrt(n);
  int sx = (i / rn) * rn;
  int sy = (j / rn) * rn;
  for (int row = sx; row < sx + rn; row++)
    for (int col = sy; col < sy + rn; col++)
      if (mat[row][col] == number)
        return false;

  return true;
}

bool solveSoduko(int mat[][9], int i, int j, int n)
{
  //Base Case
  if (i == n)
  {
    //Print the matrix
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        cout << mat[i][j] << " ";
      cout << "\n";
    }
    return true;
  }

  //Row end
  if (j == n)
    return solveSoduko(mat, i + 1, 0, n);
  //Pre-filled
  if (mat[i][j] != 0)
    return solveSoduko(mat, i, j + 1, n);

  //Recursive Case
  for (int number = 1; number <= n; number++)
  {
    if (isSafe(mat, i, j, n, number))
    {
      mat[i][j] = number;
      bool nextPlace = solveSoduko(mat, i, j + 1, n);
      if (nextPlace)
        return true;
    }
  }
  mat[i][j] = 0;
  return false;
}

int main()
{
  fastIO();

  int mat[9][9] = {
      {5, 3, 0, 0, 7, 0, 0, 0, 0},
      {6, 0, 0, 1, 9, 5, 0, 0, 0},
      {0, 9, 8, 0, 0, 0, 0, 6, 0},
      {8, 0, 0, 0, 6, 0, 0, 0, 3},
      {4, 0, 0, 8, 0, 3, 0, 0, 1},
      {7, 0, 0, 0, 2, 0, 0, 0, 6},
      {0, 6, 0, 0, 0, 0, 2, 8, 0},
      {0, 0, 0, 4, 1, 9, 0, 0, 5},
      {0, 0, 0, 0, 8, 0, 0, 7, 9}};

  solveSoduko(mat, 0, 0, 9);
  return 0;
}