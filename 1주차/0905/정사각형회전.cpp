#include<iostream>
using namespace std;

int board[100][100] = {0};


void right_turn(int& r, int& c, int& s) { // 시계방향
	int next_state[100][100];

	for (int row=0;row < s;row++) {
		for (int col=0; col < s; col++) {
			// (row,col) -> (col, size-1-row)
			next_state[col][s - 1 - row] = board[row+r][col+c];
		}
	}
	// backup
	for (int row=0;row < s;row++) {
		for (int col=0; col < s; col++) {
			board[row+r][col+c] = next_state[row][col];
		}
	}
}

void left_turn(int& r, int& c, int& s) { // 반시계방향
	int next_state[100][100];

	for (int row = 0;row < s;row++) {
		for (int col = 0; col < s; col++) {
			// (r,c) -> (size-1-c, r)
			next_state[s-1-col][row] = board[row+r][col+c];
		}
	}
	// backup (memcpy도 가능)
	for (int row = 0;row < s;row++) {
		for (int col = 0; col < s; col++) {
			board[row+r][col+c] = next_state[row][col];
		}
	}
}

int main() {

	// 파일 오픈
	//freopen_s(new FILE*, "텍스트.txt", "r", stdin);
	int N, M; // NxM 배열
	int Q; // 회전 수
	int R, C, S, D; // (R,C) 좌표 좌상단, 크기 S 정사각형, D -> 0이면 시계, 1이면 반시계
	
	cin >> N >> M >> Q;

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M;col++) {
			cin >> board[row][col];
		}
	}
	int de = -1;

	// R,C,S,D 입력
	for (int q = 0; q < Q;q++) {
		cin >> R >> C >> S >> D;
		// 회전
		if (D == 0) right_turn(R,C,S);
		else left_turn(R,C,S);
	}

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M;col++) {
			cout << board[row][col] << " ";
		}
		cout << "\n";
	}

	return 0;
}
