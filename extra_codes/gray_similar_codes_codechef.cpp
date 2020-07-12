#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

int main()
{
  ll num, n;
  cin >> num;
  vector<ll> v(num);
  for (int i = 0; i < num; i++)
  {
    cin >> n;
    if (num < 130)
      v[i] = n;
  }
  if (num >= 130)
  {
    cout << "Yes";
    return 0;
  }
  for (int i = 0; i < num; i++)
    for (int j = i + 1; j < num; j++)
      for (int k = j + 1; k < num; k++)
        for (int l = k + 1; l < num; l++)
        {
          if ((v[i] ^ v[j] ^ v[k] ^ v[l]) == 0)
          {
            cout << "Yes";
            return 0;
          }
        }
  cout << "No";
  return 0;
}