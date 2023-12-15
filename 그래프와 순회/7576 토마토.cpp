#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int M, N;
int tomato[1001][1001];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int result = 0;
bool allminus;
void Input()
{
	cin >> M >> N;
	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> tomato[i][j];
		}
}

void BFS()
{
	queue<tuple<int, int, int>> q;
	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (tomato[i][j] == 1)
				q.push(make_tuple(i, j, 0));
		}
	if (q.empty())
	{
		cout << -1;
		allminus = true;
		return;
	}
	while (!q.empty())
	{
		int y = get<0>(q.front());
		int x = get<1>(q.front());
		int cnt = get<2>(q.front());
		result = max(result, cnt);
		cnt++;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (tomato[ny][nx] == 1 || tomato[ny][nx] == -1)
				continue;
			tomato[ny][nx] = 1;
			q.push(make_tuple(ny, nx, cnt));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	BFS();
	if (allminus)
		return 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if (tomato[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
	cout << result;
	return 0;
}