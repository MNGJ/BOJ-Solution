#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N, M;
string board[100];
int result[100][100];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> board[i];
}

void BFS(int y, int x)
{
	queue<pair<int, int>> q;
	q.push(pair<int, int>(y, x));
	result[y][x] = 1;
	while (!q.empty())
	{
		int current_y = q.front().first;
		int current_x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + current_y;
			int nx = dx[i] + current_x;
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (board[ny][nx] == '0' || result[ny][nx] != 0)
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
	BFS(0, 0);

	cout << result[N-1][M-1];

	return 0;
}