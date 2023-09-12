#include <iostream>
using namespace std;

const int MAX_N = 100;
int MAP[MAX_N][MAX_N];
int M, N;


int main() {

	// Map 정보
	cin >> M >> N;
	for (int n = 0; n < N;n++) {
		for (int m = 0;m < M;m++) {
			cin >> MAP[n][m];
		}
	}

	// 방향 배열
	int rowdir[5] = { 0,-1,1,0,0 };
	int coldir[5] = { 0,0,0,-1,1 };

	int maxrow = -1, maxcol = -1;
	int maxSum = 0;
	for (int n = 0; n < N ;n++) {
		for (int m = 0;m < M;m++) {

			// [행][열]
			int sum = 0; // 매장량
			for (int t = 0;t < 5;t++) {
				int nr = n + rowdir[t];
				int nc = m + coldir[t];
				if (nr < 0 || nc < 0 || nr >= N || nc >= M)
					continue;
				sum += MAP[nr][nc];
			}
			/*
			if (n - 1 >= 0) sum += MAP[n - 1][m + 0];
			if (n + 1 < N) sum += MAP[n + 1][m + 0];
			if (m - 1 >= 0) sum += MAP[n + 0][m + -1];
			if (m + 1 < M) sum += MAP[n + 0][m + 1];
			*/

			if (maxSum < sum) {
				maxSum = sum; // 업데이트
				maxrow = n;
				maxcol = m;
			}
		}
	}
	// 결과 출력
	cout << maxcol+1 << " " << maxrow+1 << " " << maxSum << endl;
	return 0;
}
