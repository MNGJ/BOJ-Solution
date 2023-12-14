#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int test_case;
int h, w;
vector<string> map;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<char> keys;
bool visited[102][102];
int result = 0;

void Reset_Visit()
{
	for(int i = 0; i < 102; i++)
		for (int j = 0; j < 102; j++)
		{
			visited[i][j] = false;
		}
}

void Input()
{
	cin >> h >> w;
	string tmp = "";
	for (int i = 0; i < w+2; i++)
		tmp += ".";
	map.push_back(tmp);
	for (int i = 0; i < h; i++)
	{
		cin >> tmp;
		tmp = "." + tmp + ".";
		map.push_back(tmp);
	}
	tmp = "";
	for (int i = 0; i < w+2; i++)
		tmp += ".";
	map.push_back(tmp);
	cin >> tmp;
	if (tmp != "0")
	{
		for (int i = 0; i < tmp.size(); i++)
			keys.push_back(tmp[i]);
	}
}

void BFS()
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
			if (nx < 0 || nx >= w + 2 || ny < 0 || ny >= h + 2)
				continue;
			if (visited[ny][nx] || map[ny][nx] == '*')
				continue;
			if (map[ny][nx] == '$')
			{
				result++;
				map[ny][nx] = '.';
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
				continue;
			}
			if (map[ny][nx] >= 'a' && map[ny][nx] <= 'z')
			{
				keys.push_back(map[ny][nx]);
				Reset_Visit();
				while (!q.empty())
					q.pop();
				map[ny][nx] = '.';
				q.push(make_pair(ny, nx));
				continue;
			}
			if (map[ny][nx] >= 'A' && map[ny][nx] <= 'Z')
			{
				for (int k = 0; k < keys.size(); k++)
				{
					if (keys[k] - 32 == map[ny][nx])
					{
						map[ny][nx] = '.';
						visited[ny][nx] = true;
						q.push(make_pair(ny, nx));
						break;
					}
				}
				continue;
			}
			if (map[ny][nx] == '.')
			{
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
				continue;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> test_case;
	while (test_case--)
	{
		result = 0;
		map.clear();
		keys.clear();
		Reset_Visit();
		Input();
		BFS();
		cout << result << '\n';
	}

	return 0;
}