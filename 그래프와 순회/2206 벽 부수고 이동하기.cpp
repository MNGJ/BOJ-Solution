#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 987654321;

struct YX
{
	int y;
	int x;
	int cnt;
};

int N, M;
int board[1001][1001];
bool visited[1001][1001];
int break_point[1001][1001];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int result = MAX;
bool isFirstEnded;

void Input()
{
	cin >> N >> M;
	string tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		for (int j = 0; j < M; j++)
			board[i][j] = tmp[j] - '0';
	}
}

void Reset_visit()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visited[i][j] = false;
}

void BFS(int start_y, int start_x, int end_y, int end_x)
{
	queue<YX> q;
	q.push({start_y, start_x, 1});
	visited[start_y][start_x] = true;
	if (start_y == end_y && start_x == end_x)
		result = 1;
	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny == end_y && nx == end_x)
			{
				result = min(result, cnt + 1);
				continue;
			}
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx])
				continue;
			if (board[ny][nx] == 1)
			{
				if(!isFirstEnded) // (0,0)->(N-1,M-1)이 안끝났다면
				{
					if (break_point[ny][nx] == 0) // 처음 본 벽이면
						break_point[ny][nx] = cnt + 1;
				}
				else
				{
					if (break_point[ny][nx] != 0) // (0, 0) -> (N-1, M-1)때 인접한 벽이 (N-1, M-1) -> (0, 0)으로 갈때도 인접하다면
						result = min(result, break_point[ny][nx] + cnt);
				}
				continue;
			}
			q.push({ ny, nx , cnt+1});
			visited[ny][nx] = true;
		}
	}
	isFirstEnded = true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	BFS(0, 0, N-1, M-1);
	Reset_visit();
	BFS(N - 1, M - 1, 0, 0);
	int num = MAX;
	if (result == num)
		cout << -1;
	else
		cout << result;

	return 0;
}