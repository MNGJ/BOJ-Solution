#include <iostream>
#include <string>
using namespace std;

string str;
int timer, cnt = 0;

void Input()
{
	cin >> str;
	timer = (str[0]-'0') * 600 + (str[1]-'0') * 60 + (str[3]-'0') * 10 + (str[4]-'0');
}

void Solve()
{
	if (timer >= 30 && timer%600 >= 30)
	{
		timer -= 30;
	}
	while (timer != 0)
	{
		if (timer >= 600)
		{
			cnt += timer / 600;
			timer = timer % 600;
			continue;
		}
		if (timer >= 60)
		{
			cnt += timer / 60;
			timer = timer % 60;
			continue;
		}
		if (timer >= 30)
		{
			cnt += timer / 30;
			timer = timer % 30;
			continue;
		}
		if (timer >= 10)
		{
			cnt += timer / 10;
			timer = timer % 10;
			continue;
		}
	}
	cnt++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();
	cout << cnt;

	return 0;
}