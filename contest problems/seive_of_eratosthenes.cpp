// O(n * loglogn)

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
  int n;
  cin >> n;
  int arr[n+1] = {0};
  for (int i = 3; i <= n; i += 2)
    arr[i] = 1;
  for (int i = 3; i <= n; i += 2)
  {
    if (arr[i] == 1)
      for (int j = i * i; j <= n; j += i)
        arr[j] = 0;
  }
  arr[0] = arr[1] = 0;
  arr[2] = 1;
  for (int i = 0; i <= n; i++)
    if (arr[i] == 1)
      cout << i << " ";
  return 0;
}