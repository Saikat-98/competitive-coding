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

void generate_strings(char *in, char *out, int i, int j)
{
  //Base case
  if (in[i] == '\0')
  {
    out[j] = '\0';
    cout << out << "\n";
    return;
  }

  //Recursive case
  // 1. One digit at a time
  int digit = in[i] - '0';
  char ch;
  // if (digit == 0)
  //   return;
  if (digit != 0)
  {
    ch = digit + 'A' - 1;
    out[j] = ch;
    generate_strings(in, out, i + 1, j + 1);
  }

  // 2. Two digits at a time
  if (in[i + 1] != '\0')
  {
    int secondDigit = in[i + 1] - '0';
    int no = digit * 10 + secondDigit;
    if (no <= 26)
    {
      ch = no + 'A' - 1;
      out[j] = ch;
      generate_strings(in, out, i + 2, j + 1);
    }
  }

  return;
}

int main()
{
  fastIO();
  char a[100]; // digits
  cin >> a;

  char out[100];
  generate_strings(a, out, 0, 0);
  return 0;
}