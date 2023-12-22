#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<bool> isPrime(4000001, true);
vector<int> primes;
int ans = 0;

void Make_Prime()
{
	for (int i = 2; i <= N; i++)
	{
		if (!isPrime[i])
			continue;
		for (int j = i + i; j <= N; j += i)
		{
			isPrime[j] = false;
		}
	}
	for (int i = 2; i <= N; i++)
	{
		if (isPrime[i])
			primes.push_back(i);
	}
}

void check_sequence()
{
	int start = 0;
	int end = 0;
	int sum = primes[0];
	while (start < primes.size())
	{
		if (end == primes.size() - 1 && sum < N)
			return;
		if (sum == N)
		{
			ans++;
			if (start == end)
				return;
		}
		if (sum < N)
		{
			end++;
			sum += primes[end];
		}
		else
		{
			sum -= primes[start];
			start++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	if (N == 1)
	{
		cout << 0;
		return 0;
	}
	Make_Prime();
	check_sequence();
	

	cout << ans;

	return 0;
}