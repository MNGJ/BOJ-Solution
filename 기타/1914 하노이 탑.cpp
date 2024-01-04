#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int n;

void hanoi(int N, int from, int by, int to)
{
	if (N == 1)
		cout << from << " " << to << '\n';
	else
	{
		hanoi(N - 1, from, to, by);
		cout << from << " " << to << '\n';
		hanoi(N - 1, by, from, to);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	string num = to_string(pow(2, n));
	int idx = num.find('.');
	num = num.substr(0, idx);
	num[num.length() - 1] -= 1;
	if (n > 20)
		cout << num;
	else
	{
		cout << num << '\n';
		hanoi(n, 1, 2, 3);
	}

	return 0;
}