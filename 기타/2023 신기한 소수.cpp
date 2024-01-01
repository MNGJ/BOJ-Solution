#include <iostream>
#include <cmath>
using namespace std;
#define MAX 100000001;

int n;


bool isPrime(int n)
{
	if (n == 1)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}

void back_tracking(int depth, int num)
{
	if (depth == n)
	{
		cout << num << '\n';
		return;
	}
	for (int i = 1; i <= 9; i++)
	{
		int tmp = num * 10 + i;
		if (isPrime(tmp))
		{
			back_tracking(depth + 1, tmp);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	back_tracking(0, 0);

	return 0;
}