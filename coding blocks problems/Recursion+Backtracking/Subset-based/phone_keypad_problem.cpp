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

char keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void generate_names(char *in, char *out, int i, int j)
{
  //Base case
  if (in[i] == '\0')
  {
    out[j] = '\0';
    cout << out << "\n";
    return;
  }

  //Recursive case
  int digit = in[i] - '0';
  if (digit == 1 || digit == 0)
    generate_names(in, out, i + 1, j);
  for (int k = 0; keypad[digit][k] != '\0'; k++)
  {
    out[j] = keypad[digit][k];
    generate_names(in, out, i + 1, j + 1);
  }

  return;
}

int main()
{
  fastIO();
  char a[100]; // digits
  cin >> a;

  char out[100];
  generate_names(a, out, 0, 0);
  return 0;
}