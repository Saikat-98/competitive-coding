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

void subsequences(char *in, char *out, int i, int j)
{
  //Base case
  if (in[i] == '\0')
  {
    out[j] = '\0';
    cout << out << "\n";
    return;
  }
  //Recursive case
  out[j] = in[i];
  //Include current character
  subsequences(in, out, i + 1, j + 1);

  //Exclude current character
  subsequences(in, out, i + 1, j);
  return;
}

int main()
{
  fastIO();
  char input[] = "abc";
  char output[10];

  subsequences(input, output, 0, 0);

  return 0;
}