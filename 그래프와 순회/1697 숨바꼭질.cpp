#include <iostream>
#include <queue>
using namespace std;

int N, K;
bool visited[100001];

void Input()
{
	cin >> N >> K;
}

void BFS(int node)
{
	queue<pair<int, int>> q;
	q.push(make_pair(node, 0));
	visited[node] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (x == K)
		{
			cout << cnt;
			break;
		}
		if (x + 1 >= 0 && x + 1 <= 100001)
		{
			if(visited[x+1] == false)
			{
				visited[x + 1] = true;
				q.push(make_pair(x + 1, cnt + 1));
			}
		}
		if (x - 1 >= 0 && x - 1 <= 100001)
		{
			if(visited[x-1] == false)
			{
				visited[x - 1] = true;
				q.push(make_pair(x - 1, cnt + 1));
			}
		}
		if (2 * x >= 0 && 2 * x <= 100001)
		{
			if (visited[2 * x] == false)
			{
				visited[2 * x] = true;
				q.push(make_pair(2 * x, cnt + 1));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	BFS(N);

	return 0;
}