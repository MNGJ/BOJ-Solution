#include <iostream>
#include <string>
#include <vector>
using namespace std;

int R, C, K;
vector<string> RCmap;
int result = 0;
bool visited[5][5];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void Input()
{
	cin >> R >> C >> K;
	string tmp;
	for (int i = 0; i < R; i++)
	{
		cin >> tmp;
		RCmap.push_back(tmp);
	}
}

void DFS(int y, int x,int depth)
{
	if (depth == K)
	{
		if (y == 0 && x == C - 1)
		{
			result++;
		}
		return;
	}
	else 
	{
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C || RCmap[ny][nx] == 'T' || visited[ny][nx])
				continue;
			visited[ny][nx] = true;
			DFS(ny, nx, depth + 1);
			visited[ny][nx] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	visited[R - 1][0] = true;
	DFS(R-1,0,1);

	cout << result;

	return 0;
}