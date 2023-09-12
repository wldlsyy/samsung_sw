#include<iostream>
#include<vector>
using namespace std;

int N;
int cnt = 0;
bool Board[10][10] = {false}; // 전역변수 -> 원상복구 작업이 들어가야한다. 

bool isOkay(int col) {
	// col 겹치지 않는지 확인
	for (int row = 0; row < N; row++) {
		if (Board[row][col]) {
			return true;
		}
	}

	return false;
}

void dfs(int row) {
	if (row == N) {
		cnt++;
		return;
	}

	for (int col = 0; col < N;col++) {
		if (isOkay(col)) continue;

		// (row, col)에 말을 둔다
		Board[row][col] = true;
		dfs(row + 1);
		// 원상복구
		Board[row][col] = false;
	}

}

int main() {
	cin >> N; // 말 개수 겸 맵 크기

	// 말 이동
	dfs(0);
	cout << cnt << endl;

	return 0;
}
