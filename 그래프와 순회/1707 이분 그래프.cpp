#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Xset
{
	int x;
	int set;
};

int test_case;
int V, E;
vector<int> board[20001];
bool visited[20001];
bool bits[20001];
string result = "YES";
void Input()
{
	cin >> V >> E;
	int u, v;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v;
		board[u].push_back(v);
		board[v].push_back(u);
	}
	result = "YES";
}

void Reset()
{
	for (int i = 0; i < 20001; i++)
	{
		visited[i] = 0;
		bits[i] = 0;
		board[i].clear();
	}
}

void BFS()
{
	for (int i = 1; i <= V; i++)
	{
		if (board[i].size() == 0 || visited[i])
			continue;
		queue<Xset> q;
		q.push({i, 0});
		bits[i] = 0;
		visited[i] = true;
		while (!q.empty())
		{
			int x = q.front().x;
			int set = q.front().set;
			q.pop();
			for (int j = 0; j < board[x].size(); j++)
			{
				int y = board[x][j];
				if (!visited[y])
				{
					visited[y] = true;
					if (set == 1)
					{
						q.push({ y, 0 });
						bits[y] = 0;
					}
					else
					{
						q.push({ y, 1 });
						bits[y] = 1;
					}
				}
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
		Reset();
		Input();
		BFS();
		for (int i = 1; i <= V; i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				if (bits[i] == bits[board[i][j]])
				{
					result = "NO";
					break;
				}
			}
			if (result == "NO")
				break;
		}
		cout << result << '\n';
	}

	return 0;
}