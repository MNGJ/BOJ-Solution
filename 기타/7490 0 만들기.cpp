#include <iostream>
#include <string>
using namespace std;

int N;

bool parser(string str)
{
	int sum = 0;
	int temp = 0;
	char sign = '+';
	int len = str.length();

	for (int i = 0; i < len; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			temp = temp * 10 + (str[i] - '0');
			if (i == len - 1)
			{
				if (sign == '+')
					sum += temp;
				else
					sum -= temp;
			}
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			if (sign == '+')
				sum += temp;
			else
				sum -= temp;
			temp = 0;
			sign = str[i];
		}
	}
	if (sum == 0)
		return true;
	return false;
}

void make_zero(int num, string pm)
{
	if (num == N)
	{
		if (parser(pm))
			cout << pm << '\n';
		return;
	}
	make_zero(num + 1, pm + " " + to_string(num + 1));
	make_zero(num + 1, pm + "+" + to_string(num + 1));
	make_zero(num + 1, pm + "-" + to_string(num + 1));
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int Test_case;
	cin >> Test_case;
	while (Test_case--)
	{
		cin >> N;
		make_zero(1, "1");
		cout << '\n';
	}

	return 0;
}