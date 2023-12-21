#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int V, E;
int uv[401][401];
int result = INF;

void Input()
{
	for (int i = 0; i < 401; i++)
		for (int j = 0; j < 401; j++)
			uv[i][j] = INF;
	cin >> V >> E;
	int a, b, c;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		uv[a][b] = c;
	}
}

void FloydWarshall()
{
	for(int k = 1; k <= V; k++)
		for(int i = 1; i <= V; i++)
			for (int j = 1; j <= V; j++)
			{
				if (k == i || i == j || j == k)
					continue;
				if (uv[i][j] > uv[i][k] + uv[k][j])
					uv[i][j] = uv[i][k] + uv[k][j];
			}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	FloydWarshall();

	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
			result = min(result, uv[i][j] + uv[j][i]);

	if (result >= INF)
		cout << -1;
	else
		cout << result;

	return 0;
}