#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9*2;

struct XYN
{
	int x;
	int y;
	int sum;
};
int N;
vector<int> num;
XYN result = {0, 0, INF};
void Input()
{
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		num.push_back(tmp);
	}
	sort(num.begin(), num.end());
}

void Check(int left, int right, int value)
{
	if (value < result.sum)
	{
		result.sum = value;
		result.x = num[left];
		result.y = num[right];
	}
}

void Solve()
{
	int left = 0;
	int right = N - 1;
	while (left < right)
	{
		int value = abs(num[left] + num[right]);
		if (num[left] > 0)
		{
			Check(left, right, value);
			right--;
		}
		else if (num[right] < 0)
		{
			Check(left, right, value);
			left++;
		}
		else
		{
			Check(left, right, value);
			if (abs(num[left+1] + num[right]) < abs(num[left] + num[right-1]))
			{
				left++;
			}
			else
			{
				right--;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();

	cout << result.x << " " << result.y;

	return 0;
}