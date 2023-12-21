#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x;
vector<int> num;
int result = 0;

void Input()
{
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		num.push_back(tmp);
	}
	cin >> x;
	sort(num.begin(), num.end());
}

void Solve()
{
	int low = 0;
	int high = n - 1;
	while (low < high)
	{
		if (num[low] + num[high] == x)
		{
			result++;
			low++;
			high--;
		}
		else if (num[low] + num[high] > x)
			high--;
		else
			low++;
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();
	cout << result;

	return 0;
}