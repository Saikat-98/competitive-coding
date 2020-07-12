#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int num, n, sum = 0;
    cin >> num;
    vector<int> v(num + 1);
    for (int i = 1; i <= num; i++)
    {
      cin >> n;
      v[n] = abs(n - i);
      sum += abs(n - i);
    }
    auto it = find_if(v.begin(), v.end(), [](int a) {
      return a > 2;
    });
    if (v.end() != it)
    {
      cout << "Too chaotic"
           << "\n";
      continue;
    }
    cout << (sum / 2) << "\n";
  }
  return 0;
}