#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
	int row;
	int col;
};

int N, M;
int MAP[100][100];

void input() {
	cin >> N >> M;

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			cin >> MAP[row][col];
		}
	}
}

int visited[100][100];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void bfs(int r, int c) {
	queue<Node> qu;
	visited[r][c] = 1;
	qu.push({ r,c });

	while (!qu.empty()) {
		Node now = qu.front();
		qu.pop();

		// next 등록
		for (int t = 0; t < 4; t++) {
			int nr = now.row + dr[t];
			int nc = now.col + dc[t];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
			if (MAP[nr][nc] == 0) continue; // 바다
			if (visited[nr][nc]) continue; // 이미 체크
			visited[nr][nc] = 1;
			qu.push({ nr, nc });
		}
	}
}

int main() {
	input();

	int cnt = 0;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			if (MAP[row][col] == 0) continue;
			if (visited[row][col]) continue;
			bfs(row, col);
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}
