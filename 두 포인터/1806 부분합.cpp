#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 100001;
int N, S;
vector<int> num;
int result = INF;

void Input()
{
	cin >> N >> S;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		num.push_back(tmp);
	}
}

void Solve()
{
	int left = 0;
	int right = 0;
	int sum = num[0];
	int cnt = 1;
	while (left < N)
	{
		if (left == right && num[left] >= S)
		{
			result = 1;
			return;
		}
		if (sum < S)
		{
			if (right == N - 1)
				return;
			right++;
			sum += num[right];
			cnt++;
		}
		else
		{
			result = min(result, cnt);
			sum -= num[left];
			left++;
			cnt--;
		}
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();
	if (result == INF)
		cout << 0;
	else
		cout << result;

	return 0;
}