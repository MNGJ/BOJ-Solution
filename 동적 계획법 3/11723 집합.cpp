#include <iostream>
#include <string>
using namespace std;

bool arr[21];
int M;

void add(int num) { arr[num] = true; }

void remove(int num) { arr[num] = false; }

void check(int num)
{
	if (arr[num]) cout << 1 << '\n';
	else cout << 0 << '\n';
}

void toggle(int num)
{
	if (arr[num]) remove(num);
	else add(num);
}

void all() { for (int i = 1; i <= 20; i++) arr[i] = true; }

void empty() { for (int i = 1; i <= 20; i++) arr[i] = false; }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M;
	string str;
	int num;
	while (M--)
	{
		cin >> str;
		if (str != "all" && str != "empty")
			cin >> num;
		if (str == "add")
		{
			add(num);
		}
		else if (str == "remove")
		{
			remove(num);
		}
		else if (str == "check")
		{
			check(num);
		}
		else if (str == "toggle")
		{
			toggle(num);
		}
		else if (str == "all")
		{
			all();
		}
		else if (str == "empty")
		{
			empty();
		}
	}

	return 0;
}