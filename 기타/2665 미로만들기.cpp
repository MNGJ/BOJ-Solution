#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n;
int board[50][50];
bool visited[50][50];
int cnt = 0;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> erase_black;

void Reset_Visit()
{
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = false;
		}
}

void Input()
{
	cin >> n;
	string tmp;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		for (int j = 0; j < n; j++)
		{
			board[i][j] = tmp[j] - '0';
		}
	}
}

void BFS()
{
	while(1)
	{
		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));
		visited[0][0] = true;
		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int ny = dy[i] + y;
				int nx = dx[i] + x;
				if (ny == n - 1 && nx == n - 1)
					return;
				if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])
					continue;
				if (board[ny][nx] == 0)
				{
					erase_black.push(make_pair(ny, nx));
					continue;
				}
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
		cnt++;
		Reset_Visit();
		while (!erase_black.empty())
		{
			int y = erase_black.front().first;
			int x = erase_black.front().second;
			erase_black.pop();
			board[y][x] = 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	BFS();
	cout << cnt;

	return 0;
}