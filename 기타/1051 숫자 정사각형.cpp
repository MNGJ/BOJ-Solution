#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int board[50][50];
int max_result = 1;
int dx[4] = { -1, -1, 1, 1 };
int dy[4] = { -1, 1, 1, -1 };

void Input()
{
	cin >> N >> M;
	string temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		for (int j = 0; j < M; j++)
		{
			board[i][j] = temp[j]-'0';
		}
	}
}

void Solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int number = board[i][j];
			for (int k = 0; k < 4; k++)
			{
				int nx = dx[k] + i;
				int ny = dy[k] + j;
				while (nx >= 0 && nx < N && ny >= 0 && ny < M)
				{
					if (board[nx][ny] == number && board[nx][j] == number && board[i][ny] == number)
					{
						max_result = max(max_result, (nx - i + 1) * (nx - i + 1));
					}
					nx += dx[k];
					ny += dy[k];
				}
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
	cout << max_result;

	return 0;
}