#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100;
int MAP[MAX_N][MAX_N];

int main() {
	int T; // test case 개수
	cin >> T;

	vector<int> results; // 각 테스트 케이스 결과 저장

	for (int t = 1; t <= T; t++) {
		int N, P; // 마을크기, 폭탄 위력
		cin >> N >> P;

		// 바이러스 수 입력
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {
				cin >> MAP[row][col];
			}
		}

		// 방향 배열
		int rowdir[4] = { -1,1,0,0 };
		int coldir[4] = { 0,0,-1,1 };

		int maxSum = 0;
		// 최대 바이러스 수 구하기
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {
				int sum = 0;
				for (int dir = 0; dir < 4; dir++) { // 현재 위치에서 폭탄 위력에 해당하는 범위만큼
					int nr = row + rowdir[dir];
					int nc = col + coldir[dir];
					for (int p = 0; p < P; p++) {
						if (nr < 0 || nc < 0 || nr >= N || nc >= N)
							break;
						sum += MAP[nr][nc];
						nr += rowdir[dir];
						nc += coldir[dir];
					}
				}
				sum += MAP[row][col]; // 현재 위치

				if (maxSum < sum) {
					maxSum = sum; // 업데이트
				}
			}
		}
		results.push_back(maxSum); // 결과 저장
	}
	// 모든 결과 출력
	for (int t = 0; t < T; t++) {
		cout << "#" << t + 1 << " " << results[t] << endl;
	}
	return 0;
}
