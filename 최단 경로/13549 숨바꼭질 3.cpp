#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 100001;

const int INF = MAX;
int N, K;
int nodes[INF];
int dist[INF];

void Input()
{
	cin >> N >> K;
}

void dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, N });
	dist[N] = 0;
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (node == K)
		{
			cout << cost;
			return;
		}
		if (dist[node] < cost) continue;
		if(node - 1 >= 0)
		{
			if (dist[node - 1] > cost + 1)
			{
				dist[node - 1] = cost + 1;
				pq.push({ cost + 1, node - 1 });
			}
		}
		if(node + 1 <= INF)
		{
			if (dist[node + 1] > cost + 1)
			{
				dist[node + 1] = cost + 1;
				pq.push({ cost + 1, node + 1 });
			}
		}
		if(node * 2 <= INF)
		{
			if (dist[node * 2] > cost)
			{
				dist[node * 2] = cost;
				pq.push({ cost, node * 2 });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < INF; i++)
		dist[i] = INF;

	Input();
	dijkstra();

	return 0;
}