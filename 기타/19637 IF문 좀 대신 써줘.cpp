#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 

	int n, m; cin >> n >> m;

	map<int, string>arr;

	for (int i = 0; i < n; i++)
	{
		int x; string y;
		cin >> y >> x;
		arr.insert(pair<int, string>(x, y));
	}
	map<int, string>::iterator iter; 

	for (int i = 0; i < m; i++) 
	{
		int x; cin >> x;
		iter = arr.lower_bound(x);
		cout << iter->second << "\n";
	}

	return 0;
}