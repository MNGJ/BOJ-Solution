#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int test_case, N;
int start_x, start_y;
int destination_x, destination_y;
int board[301][301];
bool visited[301][301];
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
void Input();

void BFS(int node);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> test_case;
	while (test_case--)
	{
		Input();
		BFS(0);
	}

	return 0;
}

void Input()
{
	cin >> N;
	cin >> start_x >> start_y;
	cin >> destination_x >> destination_y;
	for(int i = 0; i < 301; i++)
		for (int j = 0; j < 301; j++)
		{
			board[i][j] = 0;
			visited[i][j] = false;
		}
}

void BFS(int node)
{
	queue<pair<int, int>> q;
	q.push(make_pair(start_x, start_y));
	visited[start_x][start_y] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == destination_x && y == destination_y)
		{
			cout << board[x][y] << '\n';
			return;
		}
		for (int i = 0; i < 8; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (!visited[nx][ny])
			{
				board[nx][ny] = board[x][y] + 1;
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
}