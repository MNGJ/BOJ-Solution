#include <iostream>
using namespace std;

long long N, R;
long long result;

void Input()
{
	cin >> N >> R;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	result = (N - 1) + (R*2 - 1) + 1;

	cout << result;

	return 0;
}