#include <iostream>
#include <vector>
using namespace std;

vector<int> uv[501];
int n, m;
bool visited[501];
bool is_tree;
int test_case = 0;
int cnt = 0;

void Input()
{
	is_tree = true;
	cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		uv[i].clear();
		visited[i] = false;
	}
	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		uv[u].push_back(v);
		uv[v].push_back(u);
	}
}

void Find_Tree(int node, int prev)
{
	visited[node] = true;
	for (int i = 0; i < uv[node].size(); i++)
	{
		if (uv[node][i] == prev)
			continue;
		if (visited[uv[node][i]])
		{
			is_tree = false;
			continue;
		}
		Find_Tree(uv[node][i], node);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	while (n != 0 || m != 0)
	{
		test_case++;
		Input();
		for(int i = 1; i <= n; i++)
		{
			if(!visited[i])
			{
				is_tree = true;
				Find_Tree(i, -1);
				if(is_tree)
					cnt++;
			}
		}
		if (cnt == 1)
			cout << "Case " << test_case << ": There is one tree." << '\n';
		else if(cnt > 1)
			cout << "Case " << test_case << ": A forest of " << cnt << " trees." << '\n';
		else
			cout << "Case " << test_case << ": No trees." << '\n';
		
		cin >> n >> m;
	}

	return 0;
}