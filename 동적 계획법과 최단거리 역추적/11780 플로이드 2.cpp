#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1e9

int n, m;
int d[101][101];
int route[101][101];
vector<int> v;

void Input()
{
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
		{
			if (i == j) 
			{
				d[i][j] = 0;
			}
			else d[i][j] = MAX;
		}
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		if (d[a][b] > c)
		{
			d[a][b] = c;
		}
	}
}

void Find_Route(int start, int end)
{
	if (route[start][end] == 0)
	{
		v.push_back(start);
		v.push_back(end);
		return;
	}
	Find_Route(start, route[start][end]);
	v.pop_back();
	Find_Route(route[start][end], end);
}

void Floyd_Warshall()
{
	for(int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (d[i][j] > d[i][k] + d[k][j])
				{
					d[i][j] = d[i][k] + d[k][j];
					route[i][j] = k;
				}
			}
		}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(d[i][j] >= MAX)
				cout << 0 << " ";
			else
				cout << d[i][j] << " ";
		}
		cout << '\n';
	}
	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (d[i][j] == MAX || d[i][j] == 0) cout << 0;
			else
			{
				v.clear();
				Find_Route(i, j);
				cout << v.size() << " ";
				for (auto i : v)
					cout << i << " ";
			}
			cout << '\n';
		}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Floyd_Warshall();

	return 0;
}