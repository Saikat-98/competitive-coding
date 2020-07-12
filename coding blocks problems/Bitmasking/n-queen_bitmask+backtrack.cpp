// O(k) k<n
#include <bits/stdc++.h>
using namespace std;

int n, ans = 0, DONE;
int board[100][100];

void calculate(int rowmask, int ld, int rd, int row)
{
	if (rowmask == DONE)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << board[i][j];
			cout << "\n";
		}
		cout << "\n";
		ans++;
		return;
	}

	int safe = DONE & (~(rowmask | ld | rd));
	while (safe)
	{
		int p = safe & (-safe);
		int col = __builtin_ctz(p);
		board[row][col] = 1;
		safe -= p;
		calculate(rowmask | p, (ld | p) << 1, (rd | p) >> 1, row + 1);
		board[row][col] = 0;
	}
}

int main()
{
	cin >> n;
	DONE = (1 << n) - 1;
	calculate(0, 0, 0, 0);
	cout << ans << "\n";
	return 0;
}