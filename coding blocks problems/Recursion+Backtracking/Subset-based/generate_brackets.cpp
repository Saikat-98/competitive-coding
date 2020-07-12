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

void generate_brackets(char *out, int n, int idx, int open, int close)
{
  //Base case
  if (idx == 2 * n)
  {
    out[idx] = '\0';
    cout << out << "\n";
    return;
  }

  //Recursive case
  // 2 options

  if (open < n)
  {
    out[idx] = '(';
    generate_brackets(out, n, idx + 1, open + 1, close);
  }

  if (close < open)
  {
    out[idx] = ')';
    generate_brackets(out, n, idx + 1, open, close + 1);
  }

  return;
}

int main()
{
  fastIO();
  int n;
  cin >> n;

  char out[1000];
  int idx = 0;

  generate_brackets(out, n, 0, 0, 0);

  return 0;
}