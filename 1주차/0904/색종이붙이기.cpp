#include <iostream>
using namespace std;

const int MAX_N = 100;
int MAP[MAX_N][MAX_N] = { 0 };

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N;i++) {
		int r, c;
		cin >> r >> c;
		// offset row + 0, row + 1, .. row + N-1 
		for (int row = 0; row < 10; row++) {
			for (int col = 0; col < 10;col++) {
				MAP[row+r][col+c] = 1;
			}
		}
	}
	int cnt = 0;
	for (int row = 0; row < MAX_N; row++) {
		for (int col = 0; col < MAX_N; col++) {
			if (MAP[row][col] == 1) cnt += 1;
		}
	}
	cout << cnt << endl;

	return 0;
}
