#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<long long> arr;
int N;

void Input()
{
	cin >> N;
}

void back_tracking(long long num, int level)
{
	if (level > 10) return;
	arr.push_back(num);
	for (int i = 0; i <= 9; i++)
		if(num % 10 > i)
			back_tracking(num * 10 + i, level + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	for(int i = 0; i <= 9; i++)
		back_tracking(i, 1);
	sort(arr.begin(), arr.end());

	if (N > arr.size())
		cout << -1;
	else
		cout << arr[N - 1];

	return 0;
}