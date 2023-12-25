#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
using namespace std;

const int INF = 1000000001;
int A, B;
long long result;

void Input()
{
	cin >> A >> B;
}

void Solve(long long num)
{
	if (num > B)
		return;
	if (A <= num && num <= B)
		result++;

	Solve(num * 10 + 4);
	Solve(num * 10 + 7);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve(4);
	Solve(7);

	cout << result;

	return 0;
}