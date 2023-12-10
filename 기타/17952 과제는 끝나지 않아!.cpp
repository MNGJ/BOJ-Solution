#include <iostream>
#include <stack>
using namespace std;

int N, total = 0;
stack<int> stk1;
stack<int> stk2;

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp, number, minute;
		cin >> tmp;
		if (tmp == 0)
		{
			if (stk1.empty())
				continue;
			minute = stk2.top();
			stk2.pop();
			minute--;
			if (minute == 0)
			{
				total += stk1.top();
				stk1.pop();
			}
			else
			{
				stk2.push(minute);
			}
			continue;
		}
		cin >> number >> minute;
		if (minute == 1)
		{
			total += number;
			continue;
		}
		minute--;
		stk1.push(number);
		stk2.push(minute);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	cout << total;

	return 0;
}