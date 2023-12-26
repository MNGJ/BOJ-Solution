#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAX 100001

int N, K;
int minimum[MAX];
vector<int> v;
bool finded;

void Input()
{
	cin >> N >> K;
}

void BFS()
{
	queue<int> q;
	q.push(N);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (x == K)
		{
			break;
		}
		if (x - 1 >= 0 && minimum[x-1] == -1)
		{
			q.push(x - 1);
			minimum[x - 1] = minimum[x] + 1;
		}
		if (x + 1 < MAX && minimum[x + 1] == -1)
		{
			q.push(x + 1);
			minimum[x + 1] = minimum[x] + 1;
		}
		if (2*x < MAX && minimum[2*x] == -1)
		{
			q.push(2*x);
			minimum[2*x] = minimum[x] + 1;
		}
	}
}

void Route()
{
	queue<int> q;
	q.push(K);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (x == N)
			break;
		if (x % 2 == 0 && minimum[x / 2] == minimum[x] - 1)
		{
			v.push_back(x / 2);
			q.push(x / 2);
		}
		else if (minimum[x + 1] == minimum[x] - 1)
		{
			v.push_back(x + 1);
			q.push(x + 1);
		}
		else if (minimum[x - 1] == minimum[x] - 1)
		{
			v.push_back(x - 1);
			q.push(x - 1);
		}
	}
	reverse(v.begin(), v.end());
	for (auto i : v)
		cout << i << " ";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(minimum, -1, sizeof(minimum));
	Input();
	minimum[N] = 0;
	BFS();
	v.push_back(K);
	cout << minimum[K] << '\n';
	Route();
	return 0;
}