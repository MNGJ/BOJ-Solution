#include <iostream>
using namespace std;

struct Cool
{
	long long x, y;
	bool operator<=(Cool const& p1) {
		if (x == p1.x) {
			return y <= p1.y;
		}
		return x <= p1.x;
	}
};

struct Line
{
	Cool p1;
	Cool p2;
};

Line line[2];

void Input()
{
	Cool p1, p2;
	for (int i = 0; i < 2; i++)
	{
		cin >> p1.x >> p1.y >> p2.x >> p2.y;
		line[i].p1 = p1;
		line[i].p2 = p2;
	}
}

int ccw(Cool A, Cool B, Cool C)
{
	long long s = A.x * B.y + B.x * C.y + C.x * A.y;
	s -= (A.x * C.y + B.x * A.y + C.x * B.y);

	if (s > 0) return 1;
	else if (s < 0) return -1;
	else return 0;
}

bool isline_intersect(Line& l1, Line& l2) {
	int std1, std2;

	std1 = ccw(l1.p1, l1.p2, l2.p1) * ccw(l1.p1, l1.p2, l2.p2);
	std2 = ccw(l2.p1, l2.p2, l1.p1) * ccw(l2.p1, l2.p2, l1.p2);

	if (std1 <= 0 && std2 <= 0) {
		if (std1 == 0 && std2 == 0) {     //선분이 일직선인 경우
			if (l1.p2 <= l1.p1) swap(l1.p1, l1.p2);
			if (l2.p2 <= l2.p1) swap(l2.p1, l2.p2);

			return l1.p1 <= l2.p2 && l2.p1 <= l1.p2;
		}
		else return true;   //일직선이 아니면 교차함
	}
	else return false;  //CCW가 같은 방향이 있으면 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	if (isline_intersect(line[0], line[1]))
		cout << 1;
	else
		cout << 0;

	return 0;
}