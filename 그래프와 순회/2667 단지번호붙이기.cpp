#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
string board[25];
bool visited[25][25];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int cnt = 0;
vector<int> result;

void Input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> board[i];
}

void DFS(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

		if (board[nx][ny] == '1' && !visited[nx][ny])
		{
			cnt++;
			visited[nx][ny] = true;
			DFS(nx, ny);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();

	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == '1' && visited[i][j] == false)
			{
				visited[i][j] = true;
				cnt = 1;
				DFS(i, j);
				result.push_back(cnt);
			}
		}

	cout << result.size() << '\n';

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << '\n';

	return 0;
}