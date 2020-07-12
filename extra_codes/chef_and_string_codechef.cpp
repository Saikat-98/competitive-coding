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
  int t;
  cin >> t;
  string str;
  getline(cin, str);
  while (t--)
  {
    int count = 0;
    getline(cin, str);
    for (int i = 0; i < str.length() - 1; i++)
    {
      if (str[i] != str[i + 1])
      {
        count++;
        i++;
      }
    }
    cout << count << "\n";
  }
  return 0;
}