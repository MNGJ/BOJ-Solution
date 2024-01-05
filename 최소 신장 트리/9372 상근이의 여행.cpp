#include <iostream>
#include <vector>
using namespace std;

int test_case;
int N, M;
vector<int> uv[1001];
bool visited[1001];
int ans;

void Reset_visit()
{
	for (int i = 1; i <= N; i++)
		visited[i] = false;
}

void Input()
{
	ans = 0;
	cin >> N >> M;
	Reset_visit();
	for (int i = 1; i <= N; i++)
		uv[i].clear();
	int u, v;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		uv[u].push_back(v);
		uv[v].push_back(u);
	}
}

void DFS(int node)
{
	visited[node] = true;
	for (int i = 0; i < uv[node].size(); i++)
	{
		int next_node = uv[node][i];
		if (visited[next_node])
			continue;
		ans += 1;
		DFS(next_node);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> test_case;
	while (test_case--)
	{
		Input();
		DFS(1);
		cout << ans << '\n';
	}

	return 0;
}