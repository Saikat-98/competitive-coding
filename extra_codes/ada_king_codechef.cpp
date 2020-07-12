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

int main()
{
  fastIO();
  w(t)
  {
    int n;
    cin >> n;
    char mat[8][8];
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        mat[i][j] = '.';
    mat[4][3] = 'O';
    int k = 0, l = 7;
    while (n < 64)
    {
      for (int j = k; j <= l && n < 64; j++, n++)
        mat[k][j] = 'X';
      for (int j = k + 1; j <= l && n < 64; j++, n++)
        mat[j][l] = 'X';
      for (int j = l - 1; j >= k && n < 64; j--, n++)
        mat[l][j] = 'X';
      for (int j = l - 1; j >= k + 1 && n < 64; j--, n++)
        mat[j][k] = 'X';
      k++;
      l--;
    }
    for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 8; j++)
        cout << mat[i][j];
      cout << "\n";
    }
    cout << "\n";
  }
  return 0;
}