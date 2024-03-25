#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct point {
	int x;
	int y;
};

struct line {
	point p1;
	point p2;
};

int ccw(point a, point b, point c) {
	int ret = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (ret == 0) return 0; // 일직선상에 있음
	return (ret > 0) ? 1 : -1; // 양수면 반시계방향, 음수면 시계방향
}

bool cross(line a, line b) {
	int ab = ccw(a.p1, a.p2, b.p1) * ccw(a.p1, a.p2, b.p2);
	int cd = ccw(b.p1, b.p2, a.p1) * ccw(b.p1, b.p2, a.p2);

	// 두 선분이 한 점에서 교차 & 겹치지 않을 때
	if (ab == 0 && cd == 0) {
		if (a.p1.x > a.p2.x) swap(a.p1, a.p2);
		if (b.p1.x > b.p2.x) swap(b.p1, b.p2);
		if (a.p1.x > b.p1.x) swap(a, b);

		return a.p2.x >= b.p1.x;
	}

	// 두 선분이 교차할 때
	return ab <= 0 && cd <= 0;
}

int main() {
	int N; // 선분 개수
	cin >> N;

	vector<line> lines(N);

	for (int i = 0; i < N; ++i) {
		cin >> lines[i].p1.x >> lines[i].p1.y >> lines[i].p2.x >> lines[i].p2.y;
	}

	int cnt = 0;
	// 모든 선분 쌍에 대해 교차 여부 확인
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (cross(lines[i], lines[j])) {
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}