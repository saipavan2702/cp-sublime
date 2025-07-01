#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		if (n % 2 == 0)
		{
			cout << "Yes" << endl;
			for (int i = 0; i < n / 2; i++)
			{
				cout << -1 << " " << 1 << " ";
			}
		}
		else if (n == 3)
			cout << "No";
		else
		{
			cout << "Yes" << endl;
			int r = n / 2;
			for (int i = 0; i < r; i++)
			{
				cout << 1 - r << " " << r << " ";
			}
			cout << 1 - r;
		}
		cout << endl;
	}
	return 0;
}
