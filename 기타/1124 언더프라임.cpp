#include <iostream>
#include <vector>
using namespace std;

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	int answer = 0;

	vector<bool> isPrime(b + 1, true);
	vector<int> primeCount(b + 1, 0);
	isPrime[0] = false;
	isPrime[1] = false;

	for (long long i = 2; i <= b; i++)
	{
		if (!isPrime[i])continue;
		for (long long j = i * 2; j <= b; j += i)
		{
			isPrime[j] = false;
			int tmp = j;
			while (tmp % i == 0)
			{
				tmp /= i;
				primeCount[j]++;
			}

		}
	}

	for (int i = a; i <= b; i++)
	{
		if (isPrime[i]) continue; // 소수라면 어차피 1과 자신이므로 길이가 1
		if (isPrime[primeCount[i]]) answer++;
	}

	cout << answer;

	return 0;
}