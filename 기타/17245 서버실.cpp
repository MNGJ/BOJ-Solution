#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int N;
int board[1000][1000];
long long sum = 0;
int minute = 0;

void Input()
{
	cin >> N;
	int a;
	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			sum += board[i][j];
		}
	sum = round((double)sum / 2);
}

void Solve()
{
	int low = 0, high = 10000000;
	while (low <= high)
	{
		int middle = (low + high) / 2;
		long long total = 0;
		for(int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] <= middle) total += board[i][j];
				else total += middle;
			}
		if (total >= sum)
		{
			minute = middle;
			high = middle - 1;
		}
		else
			low = middle + 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();
	cout << minute;

	return 0;
}