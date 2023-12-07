#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool visited[600][600];
string board[600];
int cnt = 0;
int Ix, Iy;

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
		if (board[i].find('I') != string::npos)
		{
			Iy = i;
			Ix = board[i].find('I');
		}
	}
}

void DFS(int x, int y)
{
	visited[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N)
			continue;
		if (board[ny][nx] == 'X' || visited[nx][ny] == true)
			continue;
		if (board[ny][nx] == 'P')
			cnt++;
		visited[nx][ny] == true;
		DFS(nx, ny);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	Input();
	DFS(Ix, Iy);
	if (cnt == 0)
		cout << "TT";
	else
		cout << cnt;

	return 0;
}