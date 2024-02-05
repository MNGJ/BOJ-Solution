#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define c first
#define v second

typedef pair<int, int> pii;
typedef long long ll;
int N, M, K;
vector<pii> beers;

bool cmp(pii a, pii b)
{
	if (a.c == b.c)
		return a.v > b.v;
	return a.c < b.c;
}

struct cmp2
{
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	int tmp1, tmp2;
	for (int i = 0; i < K; i++)
	{
		cin >> tmp1 >> tmp2;
		beers.push_back({ tmp2, tmp1 });
	}

	sort(beers.begin(), beers.end(), cmp);

	priority_queue<int, vector<int>, cmp2> pq;
	ll total = 0;

	for (auto beer : beers)
	{
		pq.push(beer.v);
		total += beer.v;

		if (pq.size() > N)
		{
			total -= pq.top();
			pq.pop();
		}

		if (pq.size() == N && total >= M)
		{
			cout << beer.c << '\n';
			return 0;
		}
	}

	cout << -1 << '\n';

	return 0;
}