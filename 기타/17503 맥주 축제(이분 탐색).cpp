#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int N, M, K;
vector<pll> beers;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	ll c_max = 0;
	for (int i = 0; i < K; i++)
	{
		ll v, c;
		cin >> v >> c;
		beers.push_back({ v, c });
		c_max = max(c_max, c);
	}

	sort(beers.begin(), beers.end(), [](pll p1, pll p2) -> bool {return p1.second < p2.second; });

	ll ans = 1e13;
	ll left = 1, right = c_max;
	while (left <= right)
	{
		ll mid = (left + right) / 2;

		ll total = 0;
		vector<ll> best;
		for (auto beer : beers)
		{
			if (beer.second > mid)
				break;
			best.push_back(beer.first);
		}

		if (best.size() < N)
		{
			left = mid + 1;
			continue;
		}

		sort(best.begin(), best.end(), [](ll a, ll b) -> bool {return a > b; });

		for (int i = 0; i < N; i++)
			total += best[i];
		
		if (total < M)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
			ans = min(ans, mid);
		}
	}

	cout << (ans != 1e13 ? ans : -1) << '\n';

	return 0;
}