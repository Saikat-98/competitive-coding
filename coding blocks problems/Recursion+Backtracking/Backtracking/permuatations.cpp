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

void permute(char *in, int i, set<string> &s)
{
  //Base case
  if (in[i] == '\0')
  {
    // cout << in << ", ";
    string t(in);
    s.insert(t);
    return;
  }

  //Recursive case
  for (int j = i; in[j] != '\0'; j++)
  {
    swap(in[i], in[j]);
    permute(in, i + 1, s);

    //Backtracking
    swap(in[i], in[j]);
  }

  return;
}

int main()
{
  fastIO();

  char in[100];
  cin >> in;
  set<string> s;

  permute(in, 0, s);

  for (auto str : s)
    cout << str << ", ";

  return 0;
}