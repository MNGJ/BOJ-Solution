#include <iostream>
#include <cmath>
using namespace std;

int sum = 0;
int a[8];
int v[8];
bool visited[8];

bool check()
{
	for (int i = 0; i < 8; i++)
	{
		int a = i;
		int b = (i + 1) % 8;
		int c = (i + 2) % 8;
		if (v[a] * v[c] * sqrt(2) > v[b] * (v[a] + v[c]))
			return false;
	}
	return true;
}

void DFS(int depth)
{
	if(depth == 8)
	{
		sum += check();
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		if (visited[i]) continue;
		visited[i] = true;
		v[depth] = a[i];
		DFS(depth + 1);
		visited[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 8; i++)
		cin >> a[i];
	DFS(0);
	cout << sum;
	return 0;
}