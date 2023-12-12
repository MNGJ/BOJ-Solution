#include <iostream>
#include <string>
#include <regex>
using namespace std;

void Solve()
{
	string bits;
	cin >> bits;

	regex r("(100+1+|01)+");
	cout << (regex_match(bits, r) ? "YES\n" : "NO\n");
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int test_case;
	cin >> test_case;
	while (test_case--)
		Solve();
}