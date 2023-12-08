#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int board[1000][1000];
int result[1000][1000];

int start_x, start_y;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void Input()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 0)
				result[i][j] = 0;
			else if (board[i][j] == 2)
			{
				result[i][j] = 0;
				start_y = i;
				start_x = j;
			}
			else
				result[i][j] = -1;
		}
}

void BFS(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(pair<int,int>(y, x));
	while (!q.empty())
	{
		int current_y = q.front().first;
		int current_x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = current_y + dy[i];
			int nx = current_x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;
			if (board[ny][nx] != 1 || result[ny][nx] != -1)
				continue;
			result[ny][nx] = result[current_y][current_x] + 1;
			q.push(pair<int, int>(ny, nx));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	BFS(start_y, start_x);

	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}