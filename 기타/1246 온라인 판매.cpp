#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, value = 0;
vector<int> board;
int max_result = 0;

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		board.push_back(temp);
	}
	sort(board.begin(), board.end(), greater<>());
}

void Solve()
{
	for (int i = 0; i < M; i++)
	{
		if (N < i+1)
			break;
		if (max_result < board[i] * (i + 1))
		{
			max_result = board[i] * (i + 1);
			value = board[i];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();
	cout << value << " " << max_result;

	return 0;
}