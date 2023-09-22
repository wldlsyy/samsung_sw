#include<iostream>
#include<vector>
using namespace std;

struct point {
	int x;
	int y;
};

// 외적 계산
int crossProduct(point& p1, point& p2) {
	return (p1.x * p2.y) - (p1.y * p2.x);
}

int main() {
	int K; // 참외 개수
	cin >> K;

	point start = { 0, 0 }; // 시작 좌표
	
	vector<point> Points;
	Points.reserve(7);

	Points.push_back(start); // 첫 좌표 넣고 시작
	
	for (int i = 0; i < 6; ++i) { // 육각형이니까
		int dir, len;
		cin >> dir >> len;
		
		point next = start;
		switch (dir) {
		case 1: // 동쪽
			next.x += len;
			break;
		case 2: // 서쪽
			next.x -= len;
			break;
		case 3: // 남쪽
			next.y -= len;
			break;
		case 4: // 북쪽
			next.y += len;
			break;
		}
		Points.push_back(next);
		start = next; // 다음 시작점 설정
	}

	// CCW 구하고
	long ccw = 0;
	int j = 0;
	for (int i = 0; i < 6; ++i) {
		j = i % 6 + 1;
		ccw += crossProduct(Points[i], Points[j]);
	}

	// 면적 구하기 -> CCW/2
	long area = abs(ccw) / 2;

	cout << area*K << endl;

	return 0;
}
