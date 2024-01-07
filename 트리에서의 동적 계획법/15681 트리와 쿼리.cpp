#include <iostream>
#include <vector>
using namespace std;

int N, R, Q;
vector<int> uv[100001];
bool visited[100001];
int dp[100001];

int Make_tree(int current_node)
{
	int result = dp[current_node];
	if (result != 0) return result;

	result = 1;
	for (int i = 0; i < uv[current_node].size(); i++)
	{
		int next_node = uv[current_node][i];
		if (!visited[next_node])
		{
			visited[next_node] = true;
			result += Make_tree(next_node);
		}
	}
	dp[current_node] = result;
	return result;
}
void Input()
{
	cin >> N >> R >> Q;
	int u, v;
	for (int i = 1; i < N; i++)
	{
		cin >> u >> v;
		uv[u].push_back(v);
		uv[v].push_back(u);
	}
}

void Solve()
{
	int tmp;
	for (int i = 0; i < Q; i++)
	{
		cin >> tmp;
		cout << Make_tree(tmp) << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	visited[R] = true;
	Make_tree(R);
	Solve();

	return 0;
}